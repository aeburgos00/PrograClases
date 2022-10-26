#include "colaDinamica.h"

#include <stdlib.h>
#include <memory.h>

void crearCola(t_cola* c){
    c->frente = NULL;
    c->fondo = NULL;
}

int encolar(t_cola* c, const void* dato, unsigned tamDato){
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return 0;
    }

    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;
    nue->sig = NULL;

    if(!c->frente) ///si esta vacia, es el primer dato
        c->frente = nue;
    else ///si no esta vacia tengo que enganchar
        c->fondo->sig = nue;

    c->fondo = nue;

    return 1;
}

int desencolar(t_cola* c, void* dato, unsigned tamDato){
    if(!c->frente)
        return 0;
    t_nodo* nae = c->frente;
    c->frente = nae->sig;

    if(!c->frente)
        c->fondo = NULL;

    memcpy(dato, nae->dato, MIN(tamDato, nae->tamDato));

    free(nae->dato);
    free(nae);

    return 1;
}

int verFrente(const t_cola* c, void* dato, unsigned tamDato){
    if(!c->frente)
        return 0;

    t_nodo* frente = c->frente;
    memcpy(dato, frente->dato, MIN(tamDato, frente->tamDato));

    return 1;
}

int colaVacia(const t_cola* c){
    return !c->frente  || !c->fondo;
}

int colaLlena(const t_cola* c, unsigned tamDato){
    t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
    void* dato = malloc(tamDato);

    free(aux);
    free(dato);

    return !aux || !dato;
}

void vaciarCola(t_cola* c){
    t_nodo* nae;
    while(!c->frente){
        nae = c->frente;
        c->frente = nae->sig;

        free(nae->dato);
        free(nae);
    }
    c->fondo = NULL;
}




