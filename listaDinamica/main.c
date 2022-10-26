#include <stdio.h>
#include <stdlib.h>

#include "listaDinamica.h"

int cmpEntero(const void* val1, const void* val2);
void mostrarEntero(void* elem, void* file);


int main()
{
    t_lista l;
    crearLista(&l);

    FILE* txt = fopen("numerosLista.txt", "wt");
    if(!txt)
        return -1;

    int a;

    a = 9;
    insertarEnListaAlFinal(&l, &a, sizeof(int));

    a = 3;
    insertarEnListaAlFinal(&l, &a, sizeof(int));

    a = 5;
    insertarEnListaAlFinal(&l, &a, sizeof(int));

    a = 1;
    insertarEnListaAlFinal(&l, &a, sizeof(int));

    ordenarLista(&l, cmpEntero);

    recorrerLista(&l, mostrarEntero, txt);

    fclose(txt);

    return 0;
}


int cmpEntero(const void* val1, const void* val2){
    return *(int*)val1 - *(int*)val2;
}

void mostrarEntero(void* elem, void* file){
    fprintf((FILE*)file,"%d ", *(int*)elem);
}
