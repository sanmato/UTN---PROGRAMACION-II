#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "persona.h"

stPersona crearPersona(void) {
    stPersona newPerson;
    
    printf("\nInsert nombre: ");
    fflush(stdin);
    gets(newPerson.nombre);

    printf("\nInsert genero: ");
    fflush(stdin);
    scanf("%c", &newPerson.genero);

    printf("\nInsert edad: ");
    fflush(stdin);
    scanf("%d", &newPerson.edad);

    return newPerson;
}

void mostrarPersona(stPersona myPerson) {
    printf("\n----------------------------------");
    printf("\nnombre: %s", myPerson.nombre);
    printf("\ngenero: %c", myPerson.genero);
    printf("\nedad: %d", myPerson.edad);
    printf("\n----------------------------------");
}

int crearArregloPersona(stPersona persons[], int dimension) {
    int validos = 0;

    while (validos < dimension) {
        persons[validos] = createPerson();
        validos++;
    }
    
    return validos;
}

void showPersonArray(stPersona persons[], int validos) {
    for(int i=0; i < validos; i++) {
        mostrarPersona(persons[i]);
    }
}