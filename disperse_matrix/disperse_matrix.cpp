#include "disperse_matrix.hpp"

disperse_matrix::disperse_matrix()
{
  m = n = 0;
  current_row = -1;
}

disperse_matrix::disperse_matrix(std::string filename)
{
  f = fopen(filename.c_str(), "r");
  fscanf(f, "%d %d", &m, &n);
  
  current_row = -1;

  scan_crs();
}

disperse_matrix::~disperse_matrix()
{
  fclose(f);
}

void disperse_matrix::add_crs(decimal_t element, int_t row, int_t col)
{
  // Add new row
  if (row > current_row)
  {
    rows.push_back(data.size() + 1);
    current_row = row;
  }
  cols.push_back(col);
  data.push_back(element);
}

void disperse_matrix::scan_crs()
{
  decimal_t data;

  for (int_t i=0; i<m; i++)
  {
    for (int_t j = 0; j < n; j++)
    {
      fscanf(f, "%lf", &data);
      
      if (data != 0.0)
        this->add_crs(data, i, j);
    }
  }

  this->rows.push_back(this->data.size() + 1);

  fclose(f);
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

disperse_matrix disperse_matrix::operator*(disperse_matrix const &m2)
{
  disperse_matrix result;

  if (n != m2.m)
  {
    fprintf(stderr, "Las matrices no pueden multiplicarse.\nTamanos incompatibles.");
    exit(1);
  }

  /*for (int_t i = 1; i <= this->data.size(); i++)
  {
    int_t k1 = this->rows[i];
    int_t k2 = this->rows[i + 1] - 1;
    decimal_t sum = 0.0;

    for (int_t j = k1; j <= k2; j++)
    {
      sum = sum + this->data[j]; // * vec(JA(j));
    }

    //vec1(i) = sum;
  }*/

  return result;
}