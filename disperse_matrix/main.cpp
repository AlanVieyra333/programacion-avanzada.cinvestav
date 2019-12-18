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

int main(int argc, char const *argv[])
{
  disperse_matrix m_a("./test/matriz_1.txt", CSR);
  disperse_matrix m_b("./test/matriz_2.txt", CSC);
  vector<decimal_t> v = read_vector("./test/vector.txt");

  printf("\nMatriz x Vector\n");
  vector<decimal_t> v_r = m_a * v;
  printf("Resultado:\n");
  for (int i = 0; i < v_r.size(); i++)
  {
    printf("%f ", v_r[i]);
  }
  printf("\n");

  printf("\nMatriz x Matriz\n");
  printf("Matriz A\n");
  m_a.print();
  printf("\nMatriz B\n");
  m_b.print();
  decimal_t *m_c = m_a * m_b;
  printf("Resultado:\n");
  for (int i = 0; i < m_a.m; i++)
  {
    for (int j = 0; j < m_a.n; j++)
    {
      printf("%f ", m_c[i*m_a.m + j]);
    }
    printf("\n");
  }
  //m_c.print();

  return 0;
}
