#include<stdio.h>
#include<stdlib.h>

#include"lista.h"

nodo* inicLista() {
    return NULL;
}

nodo* crearNodo(stNotaAlumno alumno) {
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));

    nuevo->dato = alumno;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo) {
    if(!lista) {
        lista = nuevoNodo;
    } else {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

void muestraLista(nodo* lista) {
    while(lista) {
        muestraNodo(lista);
        lista = lista->siguiente;
    }
}

void muestraNodo(nodo* nodo) {
    muestraUnaNota(nodo->dato);
}

stNotaAlumno verPrimero(nodo* lista) {
    stNotaAlumno alumno;
    if(lista) {
        alumno = lista->dato;
    }
    return alumno;
}

nodo* borrarPrimero(nodo* lista) {
    nodo* temp = lista;
    lista = lista->siguiente;
    free(temp);
    return lista;
}

nodo* buscarUltimo(nodo* lista) {
    if(lista) {
        nodo* aBuscar = lista;
        while(aBuscar->siguiente != NULL) {
            aBuscar = aBuscar->siguiente;
        }
        return aBuscar;
    }
}

nodo* agregarAlFinal(nodo* lista, nodo* aInsertar) {
    if(!lista) {
        lista = aInsertar;
    } else {
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = aInsertar;
    }

}

int cuentaNotasMayores(nodo* lista, int nota) {
    int cont = 0;
    if(lista) {
        if(lista->dato.nota > nota) {
            cont = 1+cuentaNotasMayores(lista->siguiente, nota);
        } else {
            cont = cuentaNotasMayores(lista->siguiente, nota);
        }
    }
    return cont;
}