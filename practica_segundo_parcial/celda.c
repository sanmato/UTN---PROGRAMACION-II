#include<stdio.h>
#include<stdlib.h>

#include"celda.h"

void muestraUnaCelda(celda miCelda) {
    muestraUnaMateria(miCelda.dato);
    muestraLista(miCelda.listaDeNotas);
}