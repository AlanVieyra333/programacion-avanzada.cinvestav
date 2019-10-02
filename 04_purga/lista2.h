//
//  lista2.h
//  
//
//  Created by Amilcar Meneses Viveros on 23/09/19.
//
//

#ifndef lista2_h
#define lista2_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERR_POS_NO_EXISTE      -1001
#define ERR_ELEMENTO_NO_EXISTE -1003

#define EXITO              1

#define TRUE 1
#define FALSE 0

#define LN  100
#define LD  300


typedef struct _registro {
    int numero_cuenta;
    char nombre[LN];
    char direccion[LD];
} registro;

typedef struct _nodo {
    registro r;
    struct _nodo *siguiente;
    struct _nodo *anterior;
} nodo;

typedef struct _lista {
    nodo *ultimo;
    nodo *raiz;
} lista;

// API AGREGADO
int Inicializa(lista *);
void Libera(lista *);

// API GENERAL
int Inserta(registro r, int p, lista *l);
nodo *Localiza(registro r, lista *l); // cambio
//registro Recupera(int p, registro l[]);
int Recupera(registro *r, int p, lista *l);
int Suprime(int p, lista *l);
int Siguiente(int p, lista *l);
int Anterior(int p, lista *l);
int Anula(lista *l);
int Vacia(lista *l);
int Primero(registro l[]);
void ImprimeLista(lista *l);
void Purga(lista *l);


#endif /* lista2_h */
