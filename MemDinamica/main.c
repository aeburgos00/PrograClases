#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vecE[10];
    int *p = calloc(10, sizeof(int));
    if(!p)
        return 1;
    int *p1 = malloc(10*sizeof(int));
        return 2;

    vecE[2]=2;
    *(p+2)=2;
    p1[2]=2;

    free(p1);

    p1= realloc();

    return 0;
}
