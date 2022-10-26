#ifndef PILAEST_H_INCLUDED
#define PILAEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 300

typedef struct s_nodo{
    unsigned tamDato;
    void* dato;
    struct s_nodo* sig;
}t_pila;

void crearPila(t_pila*p);
int pilaVacia(const t_pila *p);
int pilaLlena(const t_pila*p, unsigned tamDato);
void vaciarPila(t_pila*p);
int apilar(t_pila* p, const void* dato, unsigned tamDato);
int desapilar(t_pila* p, void* dato, unsigned tamDato);

#endif // PILAEST_H_INCLUDED
