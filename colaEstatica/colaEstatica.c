#include "colaEstatica.h"

void copiarDatoEnCola(t_cola* c, const void* dato, unsigned tamDato);
void copiarDatoDeCola(t_cola* c, void* dato, unsigned tamDato);

void crearCola(t_cola* c){
    c->frente = 0;
    c->fondo = 0;
    c->tamDisponible = TAM_COLA;
}

int encolar(t_cola* c, const void* dato, unsigned tamDato){
    if(tamDato+sizeof(tamDato) > c->tamDisponible)
        return 0;

    copiarDatoEnCola(c, &tamDato, sizeof(tamDato));
    copiarDatoEnCola(c, dato, tamDato);
    c->tamDisponible -= tamDato + sizeof(tamDato);

    return 1;
}

int desencolar(t_cola* c, void* dato, unsigned tamDato){
    if(c->tamDisponible == TAM_COLA)
        return 0;

    unsigned tamElemEncolado;
    copiarDatoDeCola(c, &tamElemEncolado, sizeof(tamElemEncolado));
    copiarDatoDeCola(c, dato, min(tamDato, tamElemEncolado));
    c->frente += tamElemEncolado - MIN(tamDato, tamElemEncolado);

    c->tamDisponible += tamElemEncolado + sizeof(tamElemEncolado);

    return 1;
}

int frenteDeCola(const t_cola* c, void* dato, unsigned tamDato){
    if(c->tamDisponible == TAM_COLA)
        return 0;
    unsigned frente = c->frente;

    unsigned tamDatoEncolado;
    copiarDatoDeCola(c, &tamDatoEncolado, sizeof(tamDato));
    copiarDatoDeCola(c, dato, MIN(tamDato, tamDatoEncolado));

    ((t_cola*)c)->frente = frente;

    return 1;

}

int colaVacia(const t_cola* c){
    return c->tamDisponible == TAM_COLA;
}

int colaLlena(const t_cola* c, unsigned tamDato){
    return c->tamDisponible < tamDato + sizeof(tamDato);
}

void vaciarCola(t_cola* c){
    c->frente = 0;
    c->fondo = 0;
    c->tamDisponible = TAM_COLA;
}


/* FUNCIONES INTERNAS */
void copiarDatoEnCola(t_cola* c, const void* dato, unsigned tamDato){
    unsigned tamDispCont = c->frente <= c->fondo ? TAM_COLA - c->fondo : c->frente - c->fondo;
    unsigned cantACopiar = MIN(tamDato, tamDispCont);
    memcpy(c->vCola + c->fondo, dato, cantACopiar);

    unsigned restoACopiar = tamDato - cantACopiar;
    if(restoACopiar>0)
        memcpy(c->vCola, (char*)dato + cantACopiar, restoACopiar);

    c->fondo = (c->fondo + tamDato) % TAM_COLA;
}

void copiarDatoDeCola(t_cola* c, void* dato, unsigned tamDato){
    unsigned tamDatoCont = c->frente > c->fondo ? MIN(tamDato, TAM_COLA - c->frente) : tamDato;
    memcpy(dato, c->vCola + c->frente, tamDatoCont);

    unsigned cantACopiar = tamDato - tamDatoCont;
    if(cantACopiar>0)
        memcpy((char*)dato + tamDatoCont, c->vCola, cantACopiar);

    c->frente = (c->frente + tamDato) % TAM_COLA;
}




