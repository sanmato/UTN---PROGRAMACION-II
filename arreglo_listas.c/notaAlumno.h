#ifndef NOTAALUMNO_H
#define NOTAALUMNO_H

typedef struct stNotaAlumno {
    int nota;
    int legajo;
    char nombreApe[40];
}stNotaAlumno;

void muestraUnaNota(stNotaAlumno nota);

#endif //NOTAALUMNO_H