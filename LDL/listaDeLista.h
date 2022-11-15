#ifndef LISTADELISTA_H_INCLUDED
#define LISTADELISTA_H_INCLUDED
#include "lista.h"

typedef struct _listaDeLista
{
    int idMateria;
    char materia[40];
    struct _listaDeLista* siguiente;
    nodo * listaDeNotas;
} listaDeLista;

typedef struct
{
    int idMateria;
    char materia[40];
} stMateria;


listaDeLista * inicListaLista();
listaDeLista * CrearNodoListaLista(stMateria a);
listaDeLista * AgregarAlfinalListaLista(listaDeLista* lista,listaDeLista * nuevo);

listaDeLista * buscarUltimoListaLista(listaDeLista * lista);

listaDeLista * BuscarMateriaListaLista(listaDeLista * lista,int idMat);
listaDeLista * AgregarNodoDLista();

listaDeLista *agregarAlPrincipioListaLista(listaDeLista * lista,listaDeLista * nuevo);
///

void  MuestraListaLista(listaDeLista * lista);




#endif // LISTADELISTA_H_INCLUDED
