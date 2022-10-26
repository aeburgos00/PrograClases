#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void mostrar(int x, int y);
void intercambio(int x, int y);
void intercambio1(int* x, int* y);
*/

char* str_cpy(char* destino, const char* origen);

int str_len(const char*cad);

char* str_cat(char* destino, const char*origen);

char* str_chr(char* cad, int c);

char* str_Rchr(char* cad, int c);

char* str_str(const char* cad1, const char* cad2);

int main()
{
    /*int x=2, y=10;
    printf("MAIN:\n");
    mostrar(x,y);
    intercambio(x,y);
    printf("MAIN post intercambio:\n");
    mostrar(x,y);*/
/*
    char cad5[3] = "anana";
    char* cad6 = "pepe";

    printf("%s\n",cad5);
    printf("%s\n",cad6);

    *cad5 = 'x';
    *cad6 = 'x';
    //cad5++;
    cad6++;
*/
    /*
    char cad[]="Hola";
    printf("String: %d", strlen(cad));
    printf("\nNuesta strlen: %d", str_len(cad));
    */

    /*
    char cad[20]="Hola";
    char cad2[]="Chau";
    printf("String: %s", strcat(cad, cad2));
    char cad3[20]="Hola";
    char cad4[]="Chau";
    printf("\nNuesta strcat: %s", str_cat(cad3,cad4));
    */

    /*
    char cad[20]="Hola";
    printf("String: %p", strchr(cad, 'H'));
    printf("\nNuesta strcat: %p", str_chr(cad,'H'));
    printf("\nString: %p", strchr(cad, 'a'));
    printf("\nNuesta strcat: %p", str_chr(cad,'a'));
    printf("\nString: %p", strchr(cad, 's'));
    printf("\nNuesta strcat: %p", str_chr(cad,'s'));
    */

    /*
    char cad[20]="ananx";
    printf("%p", cad);
    printf("\nString: %p", strrchr(cad, 'a'));
    printf("\nNuesta strcat: %p", str_Rchr(cad,'a'));
    printf("\nString: %p", strrchr(cad, 's'));
    printf("\nNuesta strcat: %p", str_Rchr(cad,'s'));
    */


    return 0;
}
/*
void mostrar(int x, int y)
{
    printf("X: %d\tY: %d", x,y);
}

void intercambio(int x, int y)
{
    int aux;
    aux= x;
    x=y;
    y=aux;
    printf("\n\n**********FUNCION******** \n");
    printf(" X: %d \t Y: %d \n\n", x,y);
}

void intercambio1(int* x, int* y)
{
    int* aux;
    aux= x;
    x=y;
    y=aux;
    printf("\n\n**********FUNCION******** \n");
    printf(" X: %d \t Y: %d \n\n", *x,*y);
}
*/

char* str_cpy(char* destino, const char* origen){
    char* retorno = destino;
    while(*origen){
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = *origen; ///o *destino = '\0'
    return retorno;
}

int str_len(const char*cad){
    int cont=0;
    while(*cad){
        cont++;
        cad++;
    }
    return cont;
}

char* str_cat(char* destino, const char*origen){
    char* inicioDest = destino;
    while(*destino){
        destino++;
    }
    while(*origen){
        *destino++ = *origen++;
        ///origen++;
    }
    return inicioDest;
}

char* str_chr(char* cad, int c){
    while(*cad!=c && *cad != '\0')
        cad++;
    return (*cad)?cad:NULL;
}

char* str_Rchr(char* cad, int c){
    char* aux=NULL;
    while(*cad != '\0'){
        if(*cad==c)
            aux=cad;
        cad++;
    }
    return aux;
}

char* str_str(const char* cad1, const char* cad2){
    int iguales = 0;
    char* retorno=NULL, *iniCad1=cad1;
    while( retorno!=NULL && *cad1 != '\0'){
        if(*cad1==*cad2){
            iguales = 1;
            iniCad1=cad1;
            while(*(++cad1)==*(++cad2) && *cad2 != '\0'){

            }
        }
        cad1++;
        cad2++;


        /*while(*cad1==*cad2 && *cad2 != '\0'){
            iniCad1=cad1;

        }*/
    }
    return retorno;
}
