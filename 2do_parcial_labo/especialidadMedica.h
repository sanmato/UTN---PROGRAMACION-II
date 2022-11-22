#ifndef ESPECIALIDADMEDICA_H
#define ESPECIALIDADMEDICA_H

#include"lista.h"


typedef struct stEspecialidadMedica {
    int idEspecialidad;
    char especialidadMedica[30];

}stEspecialidadMedica;

void muestraEspecialidad(stEspecialidadMedica especialidad);


#endif //ESPECIALIDADMEDICA_H