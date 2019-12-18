#include "disperse_matrix.hpp"

vector<decimal_t> read_vector(string filename)
{
  vector<decimal_t> v;
  int size = 0;
  decimal_t element;
  FILE *f = fopen(filename.c_str(), "r");

  fscanf(f, "%d", &size);

  for (int_t i = 0; i < size; i++)
  {
    fscanf(f, "%lf", &element);
    v.push_back(element);
  }

  fclose(f);

  return v;
}

void print_vector(vector<decimal_t> v, FILE *f) {
  fprintf(f, "%d\n", (int) v.size());
  for (int i = 0; i < v.size(); i++)
  {
    fprintf(f, "%f ", v[i]);
  }
  fprintf(f, "\n");
}

int main(int argc, char const *argv[])
{
  disperse_matrix m_a("./test/matriz_1.txt", CSR);
  disperse_matrix m_b("./test/matriz_2.txt", CSC);
  vector<decimal_t> v = read_vector("./test/vector.txt");
  FILE* f = fopen("./result.txt", "w");
  //FILE* f = stdout;

  printf("Matriz A\n");
  m_a.print();
  printf("\nMatriz B\n");
  m_b.print();
  printf("\nVector\n");
  print_vector(v, stdout);

  printf("\nMatriz x Vector\n");
  vector<decimal_t> v_r = m_a * v;
  printf("Resultado: result.txt\n");
  print_vector(v_r, f);

  printf("\nMatriz x Matriz\n");
  disperse_matrix m_c = m_a * m_b;
  printf("Resultado:\n");
  m_c.print();
  m_c.print_complete(f);

  fclose(f);

  return 0;
}
