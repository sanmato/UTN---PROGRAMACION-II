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

void showStack(employeeStack *empStack) {
    //ALTERNATIVE
    /*if(!isEmpty(myStack)) {
        for(int i=myStack->valid; i > 0; i--) {
            showEmployee(myStack->node[i-1]);
        }*/

    employeeStack temporalStack;
    initializeEmployeeStack(&temporalStack);

    while (!isEmpty(empStack)) {
        showEmployee(top(empStack));
        push(&temporalStack, pop(empStack));
    }
    
    while (!isEmpty(&temporalStack)) {
        push(empStack, pop(&temporalStack));
    }
}

void readWithLimit(employeeStack *employees) {
    int limit = 0;
    employee auxEmployee;
    printf("\nInsert Element numbers: ");
    scanf("%d", &limit);

    if(employees->valid < 50) {
        while(employees->valid < limit) {
            auxEmployee = loadEmployee();
            push(employees, auxEmployee);
        }      
    } else {
        printf("\nStack is full");
    }
}