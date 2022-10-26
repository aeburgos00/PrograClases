#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM 31

typedef struct{
    int dia;
    int mes;
    int anio;
}t_fecha;

typedef struct{
    int dni;
    char nya[TAM];
    t_fecha fNac;
    float prom;
}t_alumno;


#endif // FUNCIONES_H_INCLUDED
