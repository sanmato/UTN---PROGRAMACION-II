#ifndef MATERIA_H
#define MATERIA_H

typedef struct stMateria {
    int idMateria;
    char materia[40];
}stMateria;

void muestraUnaMateria(stMateria materia);

#endif //MATERIA_H