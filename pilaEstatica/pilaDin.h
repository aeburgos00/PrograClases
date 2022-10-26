#ifndef PILADIN_H_INCLUDED
#define PILADIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(A,B) ((A)>(B)?(B):(A)

typedef struct s_nodo{
    unsigned tamDato;
    void* dato;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_pila;

void crearPila(t_pila*p);
int pilaVacia(const t_pila *p);
int pilaLlena(const t_pila*p, unsigned tamDato);
void vaciarPila(t_pila*p);
int apilar(t_pila* p, const void* dato, unsigned tamDato);
int desapilar(t_pila* p, void* dato, unsigned tamDato);

#endif // PILADIN_H_INCLUDED
