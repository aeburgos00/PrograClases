#include "pilaDin.h"

void crearPila(t_pila*p){
    *p=NULL;
}

int pilaVacia(const t_pila *p){
    return (*p==NULL);
}

int pilaLlena(const t_pila*p, unsigned tamDato){
    return 0;
}

void vaciarPila(t_pila*p){
    t_pila elim;
    while(*p){
        elim = *p;
        *p = (*p)->sig;
        free(elim->dato);
        free(elim);
    }
}

int apilar(t_pila* p, const void* dato, unsigned tamDato){
    t_nodo* nue;

    return 1;
}

int desapilar(t_pila* p, void* dato, unsigned tamDato){
    t_nodo* elim;
    if(*p==NULL)
        return 0;
    elim = *P;
    *p = elim->sig;
    memcpy(dato, elim->dato, MIN(tamDato, elim->tamDato));

}

