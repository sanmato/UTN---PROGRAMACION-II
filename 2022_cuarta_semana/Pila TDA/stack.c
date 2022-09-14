#include<stdlib.h>
#include<stdio.h>

#include"IStack.h"

void initializeStack(Stack *stack) {
    (*stack) = initializeList();
}

void push(Stack *stack, int data) {
    (*stack) = pushFront(*stack, data);
}

int pop(Stack *stack) {
    int poppedStack = peek(*stack);
    
    (*stack) = popFirst(*stack);
    
    return poppedStack;
}

void showStack(Stack *stack) {
    showList(*stack);
}

int peekStack(Stack *stack) {
    int data;
    data = peek(*stack);
    return data;
}

int isEmpty(Stack stack) {
    return stack ? 1 : 0;
}