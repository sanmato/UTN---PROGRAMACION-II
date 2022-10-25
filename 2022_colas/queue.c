#include<stdio.h>
#include<stdlib.h>

#include"IQueue.h"

void initializeQueue(queueNode* queue) {
    queue->front = initializeDoubleList();
    queue->rear = initializeDoubleList();
}

void showQueue(queueNode* queue) {
    showDoublyList(queue->front);
}

void push(queueNode* queue, int data) {
    doubleNode* newNode = createNode(data);
    queue->rear = insertAtLast(queue->rear, newNode);
    if(!queue->front) {
        queue->front = queue->rear;
    }
    queue->rear = newNode;
}