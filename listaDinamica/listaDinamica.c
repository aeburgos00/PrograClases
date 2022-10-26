#include "listaDinamica.h"

#include <stdlib.h>
#include <string.h>

#define SIN_MEM -1
#define DUPLICADO -2
#define TODO_OK 2


void crearLista(t_lista* l){
    *l = NULL;
}

int insertarEnListaOrd(t_lista* l, const void* dato, unsigned tamDato, Cmp cmp){
    while(cmp(dato, (*l)->dato) > 0)
        l = &(*l)->sig;

    if(*l && cmp(dato, (*l)->dato) == 0)
        return DUPLICADO;

    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEM;
    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;

    nue->sig = *l;
    *l = nue;

    return TODO_OK;
}

int insertarOActualizarEnListaOrd(t_lista* l, const void* dato, unsigned tamDato, Cmp cmp, Actualizar act){
    while(cmp(dato, (*l)->dato) > 0)
        l = &(*l)->sig;

    if(*l && cmp(dato, (*l)->dato) == 0){
        act((*l)->dato, dato);
        return DUPLICADO;
    }

    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEM;
    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;

    nue->sig = *l;
    *l = nue;

    return TODO_OK;
}

int insertarEnListaAlInicio(t_lista* l, const void* dato, unsigned tamDato){
    return 1;
}

int insertarEnListaAlFinal(t_lista* l, const void* dato, unsigned tamDato){
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEM;
    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;
    nue->sig = NULL;

    while(*l)
        l = &(*l)->sig;

    *l = nue;

    return TODO_OK;
}

int insertarEnListaEnPosicion(t_lista* l, const void* dato, unsigned tamDato, unsigned pos){
    return 1;
}

int buscarEnListaOrd(const t_lista* l, void* dato, unsigned tamDato, Cmp cmp){
    t_nodo* actual = *l;

    while(actual && cmp(dato, actual->dato)>0) ///me fijo que actual no sea null
        actual = actual->sig;

    if(!actual || cmp(dato, actual->dato)<0)
        return 0;

    memcpy(dato, actual->dato, MIN(tamDato, actual->tamDato));

    return 1;
}

int buscarEnListaDesord(const t_lista* l, void* dato, unsigned tamDato, Cmp cmp){
    t_nodo* actual = *l;

    while(actual && cmp(dato, actual->dato)!=0) ///me fijo que actual no sea null
        actual = actual->sig;

    if(!actual)
        return 0;

    memcpy(dato, actual->dato, MIN(tamDato, actual->tamDato));

    return 1;
}

int eliminarDeListaPorValor(t_lista* l, const void* dato, unsigned tamDato, Cmp cmp){
    return 1;
}

int eliminarDeListaPorCondicion(t_lista* l, Condicion cond){
    return 1;
}

int eliminarDeListaPrimero(t_lista* l, const void* dato, unsigned tamDato){
    return 1;
}

int eliminarDeListaUltimo(t_lista* l, const void* dato, unsigned tamDato){
    return 1;
}

int eliminarDeListaOrdDuplicados(t_lista* l, Cmp cmp){
    ///DESARROLLAR
    return 1;
}

int eliminarDeListaDesordDuplicados(t_lista* l, Cmp cmp){
    ///DESARROLLAR
    return 1;
}

void ordenarLista(t_lista* l, Cmp cmp){
    t_lista lOrd = NULL;
    t_lista* plOrd;
    t_nodo* nodo;

    while(*l){
        nodo = *l;
        *l = nodo->sig;

        plOrd = &lOrd;
        while(*plOrd && cmp(nodo->dato, (*plOrd)->dato) > 0)
            plOrd = &(*plOrd)->sig;

        nodo->sig = *plOrd;
        *plOrd = nodo;
    }

    *l = lOrd;
}

int listaVacia(const t_lista*l){
    return !*l;
}

int listaLlena(const t_lista*l, unsigned tamElem){
    t_nodo* nodoAux = (t_nodo*)malloc(sizeof(t_nodo));
    void* dato = malloc(tamElem);

    free(nodoAux);
    free(dato);

    return !nodoAux || !dato;
}

int vaciarLista(t_lista*l){
    return 1;
}

void recorrerLista(const t_lista* l, Accion accion, void* datosAccion){
    while(*l){
        accion((*l)->dato, datosAccion);
        l = &(*l)->sig;
    }
}
