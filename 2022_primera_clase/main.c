#include<stdio.h>
#include<stdlib.h>

#include"IEmployeeStack.h"

void showStack(employeeStack* myStack);

int main()
{
    employeeStack stack;
    initializeEmployeeStack(&stack);

    readWithLimit(&stack);

    showStack(&stack);
    
    return 0;
}



