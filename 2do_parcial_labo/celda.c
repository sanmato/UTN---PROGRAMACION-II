#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"celda.h"

void muestraUnaCelda(celda c) {
    muestraEspecialidad(c.dato);
    muestraLista(c.lista);
}