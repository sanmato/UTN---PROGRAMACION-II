#ifndef LISTA_H
#define LISTA_H
#include "paciente.h"

typedef struct nodo{
    stPaciente dato;
    struct nodo * siguiente;
}nodo;

nodo * iniciLista();
nodo * crearNodo(stPaciente dato);
nodo * agregarAlPrincipio(nodo* lista, nodo* nuevo);
void muestraLista(nodo* lista);
void muestraNodo(nodo* n);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* agregarEnOrden(nodo* lista, nodo* nuevo);
nodo* buscarNodoPorNombreYApellido(nodo* lista, char nombre[], char apellido[]);
int contarLista(nodo* lista);
#endif // LISTA_H
