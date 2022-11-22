#ifndef CELDA_H
#define CELDA_H

#include "materia.h"
#include "listaDoble.h"

typedef struct celda {
    stMateria dato;
    nodoDoble* listaDeNotas;
}celda;

void muestraUnaCelda(celda c);

#endif //CELDA_H