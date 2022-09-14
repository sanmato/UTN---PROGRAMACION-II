#include<stdio.h>
#include<stdlib.h>

#include"IStack.h"

int main()
{
    Stack stack;
    int number, number2;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    showStack(stack);

    number2 = pop(&stack);
    system("pause");
    printf("\npopped: %d", number2);

    showStack(stack);

    system("pause");

    number = peekStack(&stack);
    printf("\npeek: %d", number);

    return 0;
}
