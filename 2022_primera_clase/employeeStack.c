#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

#include"IEmployeeStack.h"

void initializeEmployeeStack(employeeStack *employeeStack) {
    employeeStack->dimension = 50;
    employeeStack->valid = 0;
    employeeStack->node = (employee *)malloc(sizeof(employee)*employeeStack->dimension);
}

void push(employeeStack *employeeStack, employee emp) {
    if(employeeStack->valid == employeeStack->dimension) {
        employeeStack->dimension+=50;
        employeeStack->node = (employee *)realloc(employeeStack->node, sizeof(employee) * employeeStack->dimension);
    }
    employeeStack->node[employeeStack->valid] = emp;
    employeeStack->valid++;
}

employee pop(employeeStack *employeeStack) {
    employee toDelete = employeeStack->node[employeeStack->valid -1];
    employeeStack->valid--;
    return toDelete;
}

employee top(employeeStack *employeeStack) {
    return employeeStack->node[employeeStack->valid -1];
}

int isEmpty(employeeStack *employeeStack) {
    return (employeeStack->valid == 0) ? 1 : 0;
}