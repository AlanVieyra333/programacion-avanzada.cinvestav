#include "disperse_matrix.hpp"

disperse_matrix::disperse_matrix()
{
  m = n = 0;
  current_row = -1;
}

disperse_matrix::disperse_matrix(std::string filename, int compressed_type)
{
  FILE *f = fopen(filename.c_str(), "r");
  fscanf(f, "%d %d", &m, &n);

  current_row = -1;

  read_matrix(f);

  if (compressed_type == CSC)
  {
    vector<int_t> rows_csc(cols.size()), cols_csc(n + 1);
    vector<decimal_t> data_csc(data.size());

    csr2csc_serial(m, n, rows, cols, data, cols_csc, rows_csc, data_csc);

    data.clear();
    rows.clear();
    cols.clear();

    data.insert(data.end(), data_csc.begin(), data_csc.end());
    rows.insert(rows.end(), rows_csc.begin(), rows_csc.end());
    cols.insert(cols.end(), cols_csc.begin(), cols_csc.end());
  }

  fclose(f);
}

void disperse_matrix::read_matrix(FILE *f)
{
  decimal_t element;

  for (int_t row = 0; row < m; row++)
  {
    for (int_t col = 0; col < n; col++)
    {
      fscanf(f, "%lf", &element);

      if (element != 0.0)
      {
        // Add new row
        if (row > current_row)
        {
          rows.push_back(data.size());
          current_row = row;
        }

        cols.push_back(col);
        data.push_back(element);
      }
    }
  }

  this->rows.push_back(this->data.size());
}

// construct an array of size n to record current available position in each column
void disperse_matrix::csr2csc_serial(int m, int n, vector<int_t> &csrRowPtr, vector<int_t> &csrColIdx, vector<decimal_t> &csrVal, vector<int_t> &cscColPtr, vector<int_t> &cscRowIdx, vector<decimal_t> &cscVal)
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

vector<decimal_t> disperse_matrix::operator*(vector<decimal_t> const &v)
{
  vector<decimal_t> result;

  if (n != v.size())
  {
    fprintf(stderr, "La matriz no puede multiplicarse con este vector.\nTamanos incompatibles.");
    exit(1);
  }

  /* #### */
  for (int i = 0; i < v.size(); i++)
  {
    decimal_t sum = 0;
    vector<int_t> J, V;
    J.insert(J.end(), cols.begin() + rows[i], cols.begin() + rows[i + 1]);
    V.insert(V.end(), data.begin() + rows[i], data.begin() + rows[i + 1]);

    for (int k = 0; k < J.size(); k++)
    {
      sum += V[k] * v[J[k]];
    }

    result.push_back(sum);
  }

  return result;
}

disperse_matrix disperse_matrix::operator*(disperse_matrix const &m2)
{
  disperse_matrix result;

  if (n != m2.m)
  {
    fprintf(stderr, "Las matrices no pueden multiplicarse.\nTamanos incompatibles.");
    exit(1);
  }

  result.m = m;
  result.n = m2.n;

  /* #### */
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      decimal_t sum = 0;

      vector<int_t> AJ, AV, BJ, BV;
      AJ.insert(AJ.end(), cols.begin() + rows[i], cols.begin() + rows[i + 1]);
      AV.insert(AV.end(), data.begin() + rows[i], data.begin() + rows[i + 1]);

      BJ.insert(BJ.end(), m2.rows.begin() + m2.cols[j], m2.rows.begin() + m2.cols[j + 1]);
      BV.insert(BV.end(), m2.data.begin() + m2.cols[j], m2.data.begin() + m2.cols[j + 1]);

      for (int k = 0; k < AJ.size(); k++)
      {
        for (int l = 0; l < BJ.size(); l++)
        {
          if(AJ[k] == BJ[l])
            sum += AV[k] * BV[l];
        }
      }

      // Add element.
      if (sum != 0.0)
      {
        // Add new row
        if (i > result.current_row)
        {
          result.rows.push_back(result.data.size());
          result.current_row = i;
        }

        result.cols.push_back(j);
        result.data.push_back(sum);
      }
    }
  } //*/

  result.rows.push_back(result.data.size());

  return result;
}

void disperse_matrix::print()
{
  printf("Tamano: m: %u, n: %u\n", this->m, this->n);

  printf("data: ");
  for (auto &&element : data)
    printf("%f ", element);

  printf("\nrows: ");
  for (auto &&element : rows)
    printf("%d ", element);

  printf("\ncols: ");
  for (auto &&element : cols)
    printf("%d ", element);

  printf("\n"); //*/
}

void disperse_matrix::print_complete(FILE * out) {
  decimal_t element;

  fprintf(out, "%d %d\n", m, n);

  for (int_t i = 0; i < m; i++)
  {
    vector<int_t> J, V;
    J.insert(J.end(), cols.begin() + rows[i], cols.begin() + rows[i + 1]);
    V.insert(V.end(), data.begin() + rows[i], data.begin() + rows[i + 1]);

    for (int_t j = 0; j < n; j++)
    {
      element = 0;
      // Validar que se encuentre en J.
      for (int ij = 0; ij < J.size(); ij++)
      {
        if(j == J[ij]){
          element = V[ij];
          break;
        }
      }

      fprintf(out, "%lf ", element);
    }
    fprintf(out, "\n");
  }
  
}