//
//  lista2.c
//
//
//  Created by Amilcar Meneses Viveros on 23/09/19.
//
//

#include "lista2.h"

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
    } else {
        actual->anterior->siguiente = actual->siguiente;
    }

    if (actual == l->ultimo)
    {
        l->ultimo = actual->anterior;
    } else {
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
    nodo *tmp = l->raiz;
    while (tmp != NULL)
    {
        printf("%d> %d, %s, %s\n", i, tmp->r.numero_cuenta,
               tmp->r.nombre, tmp->r.direccion);
        tmp = tmp->siguiente;
        i++;
    }
}

int Vacia(lista *l)
{
    return (l->raiz == NULL) ? TRUE : FALSE;
}
