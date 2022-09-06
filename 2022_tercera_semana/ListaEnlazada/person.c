#include<stdlib.h>
#include<stdio.h>

#include "IPerson.h"

person loadPerson(void) {
    person auxPerson;

    printf("\nInsert name: ");
    fflush(stdin);
    gets(auxPerson.name); 

    printf("\nInsert gender: ");
    fflush(stdin);
    scanf("%c", &auxPerson.gender);

    printf("\nInsert edad: ");
    fflush(stdin);
    scanf("%d", &auxPerson.age);

    return auxPerson;
}

void showPerson(person personParam) {
    printf("\n------------------------------");
    printf("\n\tName: %s\t", personParam.name);
    printf("\n\tGender: %c\t", personParam.gender);
    printf("\n\tAge: %d\t", personParam.age);
    printf("\n------------------------------"); 
}