#ifndef NOTA_H_INCLUDED
#define NOTA_H_INCLUDED
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
} notaAlumno;

 void MuestraUnaNotaAlumno(notaAlumno a);


#endif // NOTA_H_INCLUDED
