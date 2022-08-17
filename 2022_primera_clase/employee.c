#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"IEmployee.h"

employee loadEmployee() {
    employee newEmployee;
    static int id = 0;
    id++;
    newEmployee.id = id;
    strcpy(newEmployee.name, "Pepe");
    strcpy(newEmployee.lastName, "Argento");
    newEmployee.age = 45;

    return newEmployee;
}

void showEmployee(employee myEmployee) {
    printf("\nID .........: %d", myEmployee.id);
    printf("\nName .......: %s", myEmployee.name);
    printf("\nLast Name...: %s", myEmployee.lastName);
    printf("\nAge .........:%d", myEmployee.age);
}