//
//  lista2.c
//
//
//  Created by Amilcar Meneses Viveros on 23/09/19.
//
//

#include "lista2.h"

int _nodosIguales(nodo *nodo1, nodo *nodo2);
void _imprimeNodo(nodo *n);

// API AGREGADO
int Inicializa(lista *l)
{
    l->ultimo = NULL;
    l->raiz = NULL;
    return EXITO;
}

void Libera(lista *l)
{
    Anula(l);
}

int Inserta(registro r, int p, lista *l)
{
    nodo *nuevo, *actual;
    int cont = 0;

    if (p == 0 && Vacia(l) == TRUE)
    {
        nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->r = r;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
        l->raiz = nuevo;
        l->ultimo = nuevo;
    }
    else
    {
        actual = l->raiz;
        for (cont = 0; cont < p; cont++)
        {
            if (actual == NULL)
                return ERR_POS_NO_EXISTE;
            actual = actual->siguiente;
        }

        nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->r = r;

        if (p == 0)
        {
            l->raiz = nuevo;
            nuevo->anterior = NULL;
        }
        else
        {
            actual->anterior->siguiente = nuevo;
            nuevo->anterior = actual->anterior;
        }

        nuevo->siguiente = actual;
        actual->anterior = nuevo;

        if (actual == NULL)
            l->ultimo = nuevo;
    }

    return EXITO;
}

nodo *Localiza(registro r, lista *l) // cambio
{
    nodo *tmp = l->raiz;

    while (tmp != NULL)
    {
        if (r.numero_cuenta == tmp->r.numero_cuenta &&
            strcmp(r.nombre, tmp->r.nombre) == 0 &&
            strcmp(r.direccion, tmp->r.direccion) == 0)
            return tmp;
        tmp = tmp->siguiente;
    }
    return tmp;
}

int Recupera(registro *r, int p, lista *l)
{
    int cont = 0;
    nodo *tmp = l->raiz;

    for (cont = 0; cont < p; cont++)
    {
        if (tmp == NULL)
            return ERR_ELEMENTO_NO_EXISTE;
        tmp = tmp->siguiente;
    }

    *r = tmp->r;
    return EXITO;
}

int Suprime(int p, lista *l)
{
    nodo *actual = l->raiz;

    if (Vacia(l) == TRUE)
        return ERR_POS_NO_EXISTE;

    for (int cont = 0; cont < p; cont++)
    {
        if (actual->siguiente == NULL)
            return ERR_POS_NO_EXISTE;
        actual = actual->siguiente;
    }

    if (actual == l->raiz)
    {
        l->raiz = actual->siguiente;
    }
    else
    {
        actual->anterior->siguiente = actual->siguiente;
    }

    if (actual == l->ultimo)
    {
        l->ultimo = actual->anterior;
    }
    else
    {
        actual->siguiente->anterior = actual->anterior;
    }

    free(actual);

    return EXITO;
}

int Anula(lista *l)
{
    nodo *tmp, *actual = l->raiz;
    while (actual != NULL)
    {
        tmp = actual;
        actual = actual->siguiente;
        free(tmp);
    }
    l->ultimo = l->raiz = NULL;
    return EXITO;
}

void ImprimeLista(lista *l)
{
    int i = 0;
    for (nodo *tmp = l->raiz; tmp != NULL; tmp = tmp->siguiente)
    {
        printf("%d> ", i++);
        _imprimeNodo(tmp);
    }
}

int Vacia(lista *l)
{
    return (l->raiz == NULL) ? TRUE : FALSE;
}

void Purga(lista *l)
{
    for (nodo *pivote = l->raiz; pivote != NULL; pivote = pivote->siguiente)
    {
        for (nodo *tmp = pivote->siguiente; tmp != NULL;)
        {
            if (_nodosIguales(pivote, tmp))
            {
                nodo* anterior = tmp->anterior;
                nodo* siguiente = tmp->siguiente;

                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;

                free(tmp);

                tmp = siguiente;
            } else {
                tmp = tmp->siguiente;
            }
        }
    }
}

void _imprimeNodo(nodo *n)
{
    printf("%d, %s, %s\n", n->r.numero_cuenta, n->r.nombre, n->r.direccion);
}

int _nodosIguales(nodo *nodo1, nodo *nodo2)
{
    registro reg1, reg2;

    if (nodo1->r.numero_cuenta == nodo2->r.numero_cuenta &&
        strcmp(nodo1->r.nombre, nodo2->r.nombre) == 0 &&
        strcmp(nodo1->r.direccion, nodo2->r.direccion) == 0)
        return TRUE;
    return FALSE;
}