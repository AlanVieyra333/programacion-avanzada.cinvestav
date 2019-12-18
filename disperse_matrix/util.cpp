//#include <omp.h>

// construct auxiliary data arrays
/*void ScanTrans(int m, int n, int nnz, int *csrRowPtr, int *csrColIdx, int *csrVal, int *cscColPtr, int *cscRowIdx, int *cscVal) {
    int *intra = new int[nnz]();
    int *inter = new int[(omp_get_num_threads() + 1) * n]();
    int *csrRowIdx = new int[nnz]();

    #pragma omp parallel for schedule(dynamic)
    for (int i=0;i<m;i++)
        for (int j = csrRowPtr[i]; j <csrRowPtr[i+1]; j++ )
            csrRowIdx[j] = i;
    
    #pragma omp parallel {
        int start, len, tid;
        // partition nnz evenly on threads, get start in csrColIdx and len for each thread
        for(int i=0;i<len;i++)
            intra[start + i] = inter[(tid + 1) * n + csrColIdx[start + i]] ++;
    }
    
    // vertical scan
    #pragma omp parallel for schedule(dynamic)
    for(int i=0;i<n;i++)
        for (int j = 1; j < nthread+1; j++)
            inter[i+n*j] += inter[i+n*(j - 1)];

    #pragma omp parallel for schedule(dynamic)
    for(int i=0;i<n;i++)
        cscColPtr[i + 1]=inter[n * nthread + i];
    prefix_sum(cscColPtr, n+1);
    
    #pragma omp parallel
    for(int i=0;i<len;i++) {
        loc = cscColPtr[csrColIdx[start + i]] + inter[tid ∗ n + csrColIdx[start + i]] + intra[start + i];
        cscRowIdx[loc] = csrRowIdx[start + i];
        cscVal[loc] = csrVal[start + i];
    }
    //free intra, inter, csrRowIdx
}*/

// construct an array of size n to record current available position in each column
void csr2csc_serial(int m, int n, int nnz, int *csrRowPtr, int *csrColIdx, int *csrVal, int *cscColPtr, int *cscRowIdx, int *cscVal)
{
    int *curr = new int[n]();

    for (int i = 0; i < m; i++)
        for (int j = csrRowPtr[i]; j < csrRowPtr[i + 1]; j++)
            cscColPtr[csrColIdx[j] + 1]++;
    // prefix_sum

    for (int i = 1; i < n + 1; i++)
        cscColPtr[i] += cscColPtr[i - 1];

    for (int i = 0; i < m; i++)
        for (int j = csrRowPtr[i]; j < csrRowPtr[i + 1]; j++)
        {
            int loc = cscColPtr[csrColIdx[j]] + curr[csrColIdx[j]]++;
            cscRowIdx[loc] = i;
            cscVal[loc] = csrVal[j];
        }
    delete[] curr;

    return;
}

int fetch_and_add(int *cscColPtr, int e) {

}

void prefix_sum(int *cscColPtr, int e) {

}

void sort_key_value(int being, int end, int *cscRowIdx, int *cscVal) {

}

void disperse_matrix::csr2csc_atomic(int m, int n, int nnz, int *csrRowPtr, int *csrColIdx, int *csrVal, int *cscColPtr, int *cscRowIdx, int *cscVal)
{
  int *dloc, loc, begin, end;

  // construct an array of size nnz to record the relative position of a nonzero element in corresponding column
  dloc = new int[nnz]();

  #pragma omp parallel for schedule(dynamic)
  for (int i = 0; i < m; i++)
    for (int j = csrRowPtr[i]; j <csrRowPtr[i+1]; j++)
      dloc[j] = fetch_and_add(&(cscColPtr[csrColIdx[j] + 1]), 1); 
  prefix_sum(cscColPtr, n+1);
  
  #pragma omp parallel for schedule(dynamic)
  for (int i = 0; i < m; i++ )
    for (int j = csrRowPtr[i]; j <csrRowPtr[i+1]; j++){
      loc = cscColPtr[csrColIdx[j]] + dloc[j];
      cscRowIdx[loc] = i;
      cscVal[loc] = csrVal[j];
    }

  // sort cscRowIdx,cscVal in each column
  #pragma omp parallel for schedule(dynamic)
  for (int i = 0; i < n; i++){
    begin=cscColPtr[i];
    end = cscColPtr[i + 1];
    sort_key_value(begin, end, cscRowIdx, cscVal);
  }
  delete[] dloc;
}
