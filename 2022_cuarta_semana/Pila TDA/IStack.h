#ifndef ISTACK_H
#define ISTACK_H

#define Stack node*

#include "ILinkedList.h"

void initializeStack(Stack *stack);
void push(Stack *stack);
void pop(Stack *stack);
void showStack(Stack stack);

#endif //ISTACK_H