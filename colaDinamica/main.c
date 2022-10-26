#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colaDinamica.h"

int main(int argc, char* argv[])
{
    t_cola cola;

    crearCola(&cola);

    for(int i=1; i < argc; i++){
        if(!encolar(&cola, argv[i], strlen(argv[i]) +1))
            return 1;
    }

    char palabra[200];

    while(!colaVacia(&cola)){
        desencolar(&cola, palabra, 200);
        puts(palabra);
    }

    return 0;
}
