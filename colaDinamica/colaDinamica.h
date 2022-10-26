#ifndef COLADINAMICA_H
#define COLADINAMICA_H

#define MIN(A,B) (A)<(B)?(A):(B)

typedef struct s_nodo{
    void* dato;
    unsigned tamDato;
    struct s_nodo* sig;
}t_nodo;

typedef struct{
    t_nodo* frente;
    t_nodo* fondo;
}t_cola;

void crearCola(t_cola* c);
int encolar(t_cola* c, const void* dato, unsigned tamDato);
int desencolar(t_cola* c, void* dato, unsigned tamDato);
int verFrente(const t_cola* c, void* dato, unsigned tamDato);
int colaVacia(const t_cola* c);
int colaLlena(const t_cola* c, unsigned tamDato);
void vaciarCola(t_cola* c);



#endif // COLADINAMICA_H
