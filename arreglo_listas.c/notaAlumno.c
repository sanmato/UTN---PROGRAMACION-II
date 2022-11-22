#include"notaAlumno.h"
#include<stdio.h>
#include<stdlib.h>

void muestraUnaNota(stNotaAlumno nota) {
    printf("\n Legajo: %d", nota.legajo);
    printf("\n Nombre y Apellido: %s", nota.nombreApe);
    printf("\n Nota: %d", nota.nota);
    printf("\n____________________________________________");
}