#ifndef PERSONA_H
#define PERSONA_H

typedef struct stPersona {
    char nombre [20];
    char genero;
    int edad;
}stPersona;

stPersona crearPersona(void);
void mostrarPersona(stPersona );
int crearArregloPersona(stPersona [], int );
void mostrarArregloPersona(stPersona [], int );


#endif //PERSONA_H