#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

nodo * iniciLista(){
    return NULL;
}

nodo * crearNodo(stPaciente dato){
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo * agregarAlPrincipio(nodo* lista, nodo* nuevo){
    nuevo->siguiente = lista;
    return nuevo;
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg!=NULL){
        muestraNodo(seg);
        seg=seg->siguiente;
    }
}

void muestraNodo(nodo* n){
    muestraUnPaciente(n->dato);
}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente != NULL){
        seg = seg->siguiente;
    }
    return seg;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

nodo* agregarEnOrden(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        if(nuevo->dato.idPaciente <= lista->dato.idPaciente){
            lista = agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg && (nuevo->dato.idPaciente > seg->dato.idPaciente)){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

nodo* buscarNodoPorNombreYApellido(nodo* lista, char nombre[], char apellido[]) {
    nodo* seg = lista;

    if(lista) {
        while(seg && (strcmp(seg->dato.nombrePaciente, nombre) !=0) && (strcmp(seg->dato.apellidoPaciente, apellido) != 0)) {
            seg = seg->siguiente;
        }
    }
    return seg;
}

int contarLista(nodo* lista) {
    int contador = 0;
    nodo* seg = lista;
    if(lista) {
        while(seg) {
            contador++;
            seg = seg->siguiente;
        }
    }
    return contador;
}


