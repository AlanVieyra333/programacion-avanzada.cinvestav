#include <stdio.h>
#include "lista2.h"

int main()
{
  lista l;
  registro r;
  int err;

  Inicializa(&l);

  r.numero_cuenta = 1234;
  strcpy(r.nombre, "Fulano");
  strcpy(r.direccion, "Alla");
  err = Inserta(r, 0, &l);

  r.numero_cuenta = 2345;
  strcpy(r.nombre, "Sutano");
  strcpy(r.direccion, "Aca");
  err = Inserta(r, 0, &l);

  r.numero_cuenta = 3456;
  strcpy(r.nombre, "Mengano");
  strcpy(r.direccion, "Aqui");
  err = Inserta(r, 0, &l);

  r.numero_cuenta = 4567;
  strcpy(r.nombre, "Perengano");
  strcpy(r.direccion, "Por alla");
  err = Inserta(r, 0, &l);

  ImprimeLista(&l);
  printf("======\n");

  Recupera(&r, 0, &l);
  printf("<%d,%s,%s>\n", r.numero_cuenta, r.nombre, r.direccion);
  printf("======\n");

  Suprime(0, &l);
  ImprimeLista(&l);
  printf("======\n");

  Suprime(2, &l);
  ImprimeLista(&l);
  printf("======\n");
  
  r.numero_cuenta = 1234;
  strcpy(r.nombre, "Fulano");
  strcpy(r.direccion, "Alla");
  err = Inserta(r, 1, &l);
  ImprimeLista(&l);
  printf("======\n");

  Anula(&l);
  ImprimeLista(&l);
  printf("======\n");

  Libera(&l);
}
