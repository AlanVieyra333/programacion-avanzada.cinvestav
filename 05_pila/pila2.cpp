//
//  pila.cpp
//  
//
//  Created by Amilcar Meneses Viveros on 07/10/19.
//
//
#include <iostream>
#include "pila.hpp"

using namespace std;

#define N 10

class elemento {
    int _dato;
    elemento *_ultimo;

public:

    void setDato(int dato) {
        _dato = dato;
    }

    int getDato() {
        return _dato;
    }

    void setUltimo(elemento* ultimo) {
        _ultimo = ultimo;
    }

    elemento *getUltimo() {
        return _ultimo;
    }
};

class Pila {
    elemento  *tope;
   
public:
    Pila() {
        tope=NULL;
    }
    
    int push(int e) {
        elemento *tmp; 
        tmp = (elemento *)malloc(sizeof(elemento)); 
        tmp->setDato(e); 
        tmp->setUltimo(tope); 
        tope = tmp;  
        return EXITO;
    }

    int pop() {
        elemento *tmp; 
        int e; 
        if (vacia()==YES) return ERR_PILA_VACIA;
        tmp = tope; 
        e = tmp->getDato();
        tope = tmp->getUltimo(); 
        free(tmp);  
       return e;
    }
    
    int vacia() {
        return (tope==NULL)?YES: NO;
    }
    
    void vaciar() {
        while (tope != NULL) 
           pop(); 
    }
    
    void imprime() {
        int i=0; 
        elemento *tmp = tope; 

        while (tmp != NULL) {
           cout << i++ << "\t" << tmp->getDato() << endl; 
           tmp = tmp->getUltimo(); 
       }
    }
 
};

int main() {
    Pila p;
    int i;
    for (i=0; i<N/2; i++) {
        p.push(i+2);
    }
    
    p.imprime();
    cout << "================" << endl;
    
    i = p.pop();
    cout << i << endl;

    cout << "================" << endl;
    p.imprime();
    cout << "================" << endl;

    
    p.vaciar();
    p.imprime();
    return 0;
}
