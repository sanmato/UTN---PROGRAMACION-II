#include<stdio.h>
#include<stdlib.h>

#include"IEmployeeStack.h"

void showStack(employeeStack* myStack);

int main()
{
    employeeStack stack;
    initializeEmployeeStack(&stack);

    employee employee;

    push(&stack, loadEmployee());
    push(&stack, loadEmployee());
    push(&stack, loadEmployee());
    push(&stack, loadEmployee());
    push(&stack, loadEmployee());

    showStack(&stack);

    return 0;
}

void showStack(employeeStack *myStack) {
    employeeStack aux;
    if(!isEmpty(myStack)) {
        for(int i=myStack->valid; i >= 0; i--) {
            showEmployee(myStack->node[i]);
        }
    }
}


