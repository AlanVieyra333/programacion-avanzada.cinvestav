#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double (*func)(double);

func functions[] = {sin, cos};

double integral(func);

int main()
{
  printf("##### Arreglo de Funciones #####\n\n");

  int functions_size = sizeof(functions) / sizeof(func); // Array size.

  for (int i = 0; i < functions_size; i++)
  {
    double _integral = integral(functions[i]);
    printf("Integral de 0 a 1: %lf\n", _integral);
  }

  return 0;
}

double integral(func function)
{
  double result = function(1) - function(0);

  return result;
}
