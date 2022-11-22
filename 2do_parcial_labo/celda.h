#ifndef CELDA_H
#define CELDA_H

#include"lista.h"
#include"especialidadMedica.h"

typedef struct celda {
    stEspecialidadMedica dato;
    nodo* lista;
}celda;

void muestraUnaCelda(celda c);


#endif // CELDA_H