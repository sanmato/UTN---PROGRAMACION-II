#ifndef IQUEUE_H
#define IQUEUE_H

#include"IDoublyLinkedList.h"

typedef struct queueNode{
    struct doubleNode *front;
    struct doubleNode *rear;
}queueNode;

void initializeQueue(queueNode* queue);
void showQueue(queueNode* queue);

#endif //IQUEUE_H