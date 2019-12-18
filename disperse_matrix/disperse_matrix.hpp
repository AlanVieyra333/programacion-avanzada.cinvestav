#ifndef DISPERSE_MATRIX_HPP
#define DISPERSE_MATRIX_HPP

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
//#include <omp.h>

#define CSR 0
#define CSC 1

typedef int int_t;
typedef double decimal_t;

using namespace std;

/**
 * Disperse matrix using the CSR (Compressed Sparse Row) and
 * CSC (Compressed Sparse Column) format.
 * 
 * @Author Alan Fernando Rincón VIeyra
*/
class disperse_matrix
{
private:
  void csr2csc_serial(int m, int n, vector<int_t> &csrRowPtr, vector<int_t> &csrColIdx, vector<decimal_t> &csrVal, vector<int_t> &cscColPtr, vector<int_t> &cscRowIdx, vector<decimal_t> &cscVal);

public:
  int_t m, n; // m - rows, n - cols
  vector<int_t> rows, cols;
  vector<decimal_t> data;
  int_t current_row;

  disperse_matrix();
  disperse_matrix(string filename, int compressed_type);
  void read_matrix(FILE *f);
  void csr2csc_atomic(int m, int n, int nnz, int *csrRowPtr, int *csrColIdx, int *csrVal, int *cscColPtr, int *cscRowIdx, int *cscVal);
  void print();
  vector<decimal_t> operator*(vector<decimal_t> const &v);
  disperse_matrix operator*(disperse_matrix const &m2);
  void print_complete(FILE * out);
};

#endif
