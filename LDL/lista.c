#include "lista.h"

nodo * inicLista()
{

    return NULL;
}

nodo * crearNodoLista(notaAlumno n)
{

    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato= n;
    nuevo->siguiente = NULL;


    return nuevo;
}


nodo * AgregarAlfinalLista(nodo * lista,nodo * nuevo)
{
    nodo * ultimo = NULL;



    if(lista==NULL)
    {
        lista = nuevo;

    }
    else
    {

        ultimo = buscarUltimoLista(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}


nodo* buscarUltimoLista(nodo* lista)
{
    if(lista)
    {
        while(lista->siguiente != NULL)
        {
            lista = lista->siguiente;
        }
    }
    return lista;
}


void MuestraLista(nodo * lista)
{
    nodo * seg = lista;

    while(seg != NULL)
    {
        MuestraUnaNotaAlumno(seg->dato);

        seg=seg->siguiente;

    }
}

nodo *agregarAlPrincipioLista(nodo * lista,nodo * nuevo)
{
    nuevo->siguiente=lista;

    return nuevo;
}
