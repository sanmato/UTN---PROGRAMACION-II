#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nota.h"


typedef struct _nodo
{
    notaAlumno dato;
    struct _nodo *siguiente;
} nodo;

nodo * inicLista();
nodo * crearNodoLista(notaAlumno n);
nodo * AgregarAlfinalLista(nodo* lista, nodo * nuevo);
nodo * buscarUltimoLista(nodo * lista);
///
nodo *agregarAlPrincipioLista(nodo * lista,nodo * nuevo);
///
void  MuestraLista(nodo * lista);



#endif // LISTA_H_INCLUDED
