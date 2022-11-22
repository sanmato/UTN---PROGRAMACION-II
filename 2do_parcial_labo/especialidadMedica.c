#include<stdlib.h>
#include<stdio.h>

#include"especialidadMedica.h"

void muestraEspecialidad(stEspecialidadMedica especialidad) {
    printf("\n Nombre de la especialidad Medica: %s", especialidad.especialidadMedica);
    printf("\nID de la especialidad: %d", especialidad.idEspecialidad);
    printf("\n____________________________________________________________");
}