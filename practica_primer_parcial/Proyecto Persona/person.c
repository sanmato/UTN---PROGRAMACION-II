#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "IPerson.h"

person createPerson() {
    person newPerson;
    
    printf("\nInsert name: ");
    fflush(stdin);
    gets(newPerson.name);

    printf("\nInsert gender: ");
    fflush(stdin);
    scanf("%c", &newPerson.gender);

    printf("\nInsert age: ");
    fflush(stdin);
    scanf("%d", &newPerson.age);

    return newPerson;
}

void showPerson(person myPerson) {
    printf("\n----------------------------------");
    printf("\nName: %s", myPerson.name);
    printf("\nGender: %c", myPerson.gender);
    printf("\nAge: %d", myPerson.age);
    printf("\n----------------------------------");
}

int createPersonArray(person persons[], int dimension) {
    int elements = 0;

    while (elements < dimension) {
        persons[elements] = createPerson();
        elements++;
    }
    
    return elements;
}

void showPersonArray(person persons[], int elements) {
    for(int i=0; i < elements; i++) {
        showPerson(persons[i]);
    }
}