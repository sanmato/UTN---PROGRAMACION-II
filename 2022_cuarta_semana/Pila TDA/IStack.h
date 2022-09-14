#ifndef ISTACK_H
#define ISTACK_H

#define Stack node*

#include "ILinkedList.h"

void initializeStack(Stack *stack);
void push(Stack *stack, int );
int pop(Stack *stack);
void showStack(Stack *stack);
int peekStack(Stack *stack);
int isEmpty(Stack stack);

#endif //ISTACK_H