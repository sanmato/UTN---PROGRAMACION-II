#ifndef IEMPLOYEESTACK_H
#define IEMPLOYEESTACK_H

#include "IEmployee.h"

typedef struct {
    employee *node;
    int valid;
    int dimension;
}employeeStack;

void initializeEmployeeStack(employeeStack *employeeStack);
void push(employeeStack *employeeStack, employee employee);
employee pop(employeeStack *employeeStack);
employee top(employeeStack *employeeStack);
int isEmpty(employeeStack *employeeStack);
void showStack(employeeStack *empStack);
void readWithLimit(employeeStack *employees);

#endif