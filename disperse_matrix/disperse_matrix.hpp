#ifndef DISPERSE_MATRIX_HPP
#define DISPERSE_MATRIX_HPP

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

typedef unsigned int int_t;
typedef double decimal_t;

/**
 * Disperse matrix using the CRS (Compressed Row Storage) and
 * CCS (Compressed Column Storage) format.
 * 
 * @Author Alan Fernando Rincón VIeyra
*/
class disperse_matrix
{
private:
  FILE *f;
  std::vector<int_t> rows, cols;
  std::vector<decimal_t> data;
  int_t m, n; // m - rows, n - cols
  int_t current_row;

public:
  disperse_matrix();
  disperse_matrix(std::string filename);
  ~disperse_matrix();
  void add_crs(decimal_t element, int_t row, int_t col);
  void scan_crs();
  void scan_ccs();
  void print();
  disperse_matrix operator*(disperse_matrix const &m2);
};

#endif
