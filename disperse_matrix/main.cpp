#include "disperse_matrix.hpp"

int main(int argc, char const *argv[])
{
  disperse_matrix m_a("./test/matriz_1.txt"), m_b("./test/matriz_2.txt");
  m_a.print();
  m_b.print();
  disperse_matrix m_c = m_a * m_b;

  return 0;
}
