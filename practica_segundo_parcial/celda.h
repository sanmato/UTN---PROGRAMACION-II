#ifndef CELDA_H
#define CELDA_H

#include "materia.h"
#include "lista.h"

typedef struct celda {
    stMateria dato;
    nodo* listaDeNotas;
}celda;

void muestraUnaCelda(celda );

#endif //CELDA_H