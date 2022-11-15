#include "listaDeLista.h"

listaDeLista * inicListaLista()
{
    return NULL;
}

listaDeLista * CrearNodoListaLista(stMateria a)
{
    listaDeLista * nuevo = (listaDeLista*) malloc(sizeof(listaDeLista));
    nuevo->siguiente = NULL;
    nuevo->idMateria =a.idMateria;

    strcpy(nuevo->materia,a.materia);
    nuevo->listaDeNotas=NULL;

    return nuevo;
}

listaDeLista * AgregarAlfinalListaLista (listaDeLista * lista,listaDeLista * nuevo)
{
    listaDeLista * ultimo =NULL;

    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        ultimo = buscarUltimoListaLista(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}

listaDeLista * BuscarMateriaListaLista(listaDeLista * lista,int idMat)
{
    listaDeLista * seg = lista;

    listaDeLista * buscado = NULL;

    int flag = 0;

    if(lista)
    {
        while(flag == 0 && seg->siguiente !=NULL)
        {

            if(seg->idMateria==idMat)
            {
                buscado=seg;
                flag = 1;
            }

            seg=seg->siguiente;
        }
    }

    return buscado;
}

listaDeLista* buscarUltimoListaLista(listaDeLista* lista)
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

listaDeLista *agregarAlPrincipioListaLista(listaDeLista * lista,listaDeLista * nuevo)
{
    nuevo->siguiente=lista;
    return nuevo;
}

void MuestraListaLista(listaDeLista * lista)
{
     listaDeLista * seg = lista;

    while(seg != NULL)
    {

        printf("\n********%s********\n",seg->materia);

        MuestraLista(seg->listaDeNotas);

        printf("\n");

        seg=seg->siguiente;
    }
}
