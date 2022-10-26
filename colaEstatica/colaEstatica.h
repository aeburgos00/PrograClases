#ifndef COLAESTATICA_H
#define COLAESTATICA_H

#include <stdlib.h>
#include <string.h>

#define TAM_COLA 5000

#define MIN(A,B) (A)<(B)? (A) : (B)

typedef struct{
    char vCola[TAM_COLA];
    unsigned frente;
    unsigned fondo;
    size_t tamDisponible;
}t_cola;

void crearCola(t_cola* c);
int encolar(t_cola* c, const void* dato, unsigned tamDato);
int desencolar(t_cola* c, void* dato, unsigned tamDato);
int verFrente(const t_cola* c, void* dato, unsigned tamDato);
int colaVacia(const t_cola* c);
int colaLlena(const t_cola* c, unsigned tamDato);
void vaciarCola(t_cola* c);

#endif // COLAESTATICA_H
