#include "materia.h"

#include<stdio.h>
#include<stdlib.h>

void muestraUnaMateria(stMateria materia) {
    printf("\nID: %d", materia.idMateria);
    printf("\nNombre materia: %s", materia.materia);
    printf("\n___________________________________________________");
}