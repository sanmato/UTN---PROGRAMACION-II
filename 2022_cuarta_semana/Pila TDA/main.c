#include<stdio.h>
#include<stdlib.h>

#include"IStack.h"

int main()
{
    Stack stack;
    initializeStack(&stack);

    push(&stack);
    push(&stack);
    push(&stack);

    showStack(stack);

    printf("\n");
    system("pause");

    pop(&stack);

    showStack(stack);

    return 0;
}
