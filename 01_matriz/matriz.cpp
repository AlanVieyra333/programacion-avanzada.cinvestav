#include <stdio.h>
#include <stdlib.h>

#define m 5
#define n 7

typedef int **Matriz;

Matriz crearMatriz(int _m, int _n);
Matriz sumaMatrices(Matriz a, Matriz b, int _m, int _n);
void imprimirMatriz(int *matriz, int _m, int _n);

int main()
{
  Matriz matriz1 = crearMatriz(m, n);
  Matriz matriz2 = crearMatriz(m, n);

  printf("##### SUMA DE MATRICES #####\n");

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matriz1[i][j] = i;
      matriz2[i][j] = j;
    }
  }

  imprimirMatriz(*matriz1, m, n);
  imprimirMatriz(*matriz2, m, n);

  Matriz matriz3 = sumaMatrices(matriz1, matriz2, m, n);

  imprimirMatriz(*matriz3, m, n);

  return 0;
}

Matriz crearMatriz(int _m, int _n)
{
  Matriz matriz = (Matriz)malloc(_m * sizeof(int *));     // Reservar memorai para los apuntadores a arreglo.
  int *matrizData = (int *)malloc(_m * _n * sizeof(int)); // Reservar memoria para la matriz.

  for (int i = 0; i < _n; i++)
  {
    matriz[i] = &matrizData[i * _n];
  }

  return matriz;
}

Matriz sumaMatrices(Matriz a, Matriz b, int _m, int _n)
{
  Matriz result = crearMatriz(_m, _n);

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      result[i][j] = a[i][j] + b[i][j];
    }
  }

  return result;
}

void imprimirMatriz(int *matriz, int _m, int _n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matriz[i * n + j]);
    }
    printf("\n");
  }
  printf("\n");
}
