#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"IEmployee.h"

employee loadEmployee() {
    employee newEmployee;
    static int id = 0;
    id++;
    newEmployee.id = id;

    printf("\nName: ");
    fflush(stdin);
    gets(newEmployee.name);

    printf("\nLast Name: ");
    fflush(stdin);
    gets(newEmployee.lastName);

    printf("\nAge: ");
    fflush(stdin);
    scanf("%d", &newEmployee.age);

    return newEmployee;
}

void showEmployee(employee myEmployee) {
    printf("\n-----------------------------------");
    printf("\nID .........: %d", myEmployee.id);
    printf("\nName .......: %s", myEmployee.name);
    printf("\nLast Name...: %s", myEmployee.lastName);
    printf("\nAge ........: %d", myEmployee.age);
    printf("\n-----------------------------------");
}