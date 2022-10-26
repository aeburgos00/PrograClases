#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#define MIN(A,B) (A)<(B)?(A):(B)

typedef struct s_nodo{
    void* dato;
    unsigned tamDato;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

typedef int (*Cmp)(const void* e1, const void* e2);
typedef void (*Accion)(void*, void*);

typedef int (*Condicion)(const void* elem);
typedef void (*Actualizar)(void* actualizado, const void* actualizador);

void crearLista(t_lista* l);
int insertarEnListaAlFinal(t_lista* l, const void* dato, unsigned tamDato);
void ordenarLista(t_lista* l, Cmp cmp);
void recorrerLista(const t_lista* l, Accion accion, void* datosAccion);



int insertarEnListaOrd(t_lista* l, const void* dato, unsigned tamDato, Cmp cmp);
int insertarOActualizarEnListaOrd(t_lista* l, const void* dato, unsigned tamDato, Cmp cmp, Actualizar act);
int insertarEnListaAlInicio(t_lista* l, const void* dato, unsigned tamDato);
int insertarEnListaEnPosicion(t_lista* l, const void* dato, unsigned tamDato, unsigned pos);
int buscarEnListaOrd(const t_lista* l, void* dato, unsigned tamDato, Cmp cmp);
int buscarEnListaDesord(const t_lista* l, void* dato, unsigned tamDato, Cmp cmp);
int eliminarDeListaPorValor(t_lista* l, const void* dato, unsigned tamDato, Cmp cmp);
int eliminarDeListaPorCondicion(t_lista* l, Condicion cond);
int eliminarDeListaPrimero(t_lista* l, const void* dato, unsigned tamDato);
int eliminarDeListaUltimo(t_lista* l, const void* dato, unsigned tamDato);
int eliminarDeListaOrdDuplicados(t_lista* l, Cmp cmp);
int eliminarDeListaDesordDuplicados(t_lista* l, Cmp cmp);
int listaVacia(const t_lista*l);
int listaLlena(const t_lista*l, unsigned tamElem);
int vaciarLista(t_lista*l);



#endif // LISTADINAMICA_H
