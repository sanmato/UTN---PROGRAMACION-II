#ifndef LISTA_H
#define LISTA_H


#include <stdio.h>
#include <stdlib.h>
#include "notaAlumno.h"

typedef struct nodo {
    stNotaAlumno dato;
    struct nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stNotaAlumno );
nodo* agregarAlPrincipio(nodo* , nodo* );
void muestraLista(nodo* );
void muestraNodo(nodo* );
stNotaAlumno verPrimero(nodo* );
nodo* borrarPrimero(nodo* );
nodo* buscarUltimo(nodo* );
nodo* agregarAlFinal(nodo* , nodo* );
int cuentaNotasMayores(nodo* , int );


#endif //LISTA_H