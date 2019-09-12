#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INFINITE 10000
#define A 0.0
#define B 1.0

typedef double (*func)(double);
func functions[] = {sin, cos};

double definiteIntegral(func, double, double);

int main()
{
  printf("##### Integral de Funciones en un Arreglo #####\n\n");

  int functions_size = sizeof(functions) / sizeof(func);

  for (int i = 0; i < functions_size; i++)
  {
    double _integral = definiteIntegral(functions[i], A, B);
    printf("Integral de la funcion %d, de %.1lf a %.1lf: %lf\n", (i+1), A, B, _integral);
  }

  return 0;
}

double definiteIntegral(func f, double a, double b)
{
  double _integral = 0.0;
  int n = INFINITE; // 'n' tiende a infinito.
  double dx = (b - a) / n;

  for (int i = 1; i<= n; i++) {
    double xi = a + (dx * i);
    _integral += f(xi) * dx;
  }

  return _integral;
}
