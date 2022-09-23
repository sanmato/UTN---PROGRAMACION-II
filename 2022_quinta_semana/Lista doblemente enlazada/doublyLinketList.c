#include<stdio.h>
#include<stdlib.h>

#include "IDoublyLinkedList.h"

doubleNode* initializeDoubleList(void) {
    return NULL;
}

doubleNode* createNode(int data) {
    doubleNode* newNode;
    newNode = (doubleNode*)malloc(sizeof(doubleNode));
    newNode->data = data;
    newNode->previousNode = NULL;
    newNode->nextNode = NULL;
    return newNode;
}

void insertAtFront(doubleNode **doublyList, doubleNode* newNode) {
    newNode->nextNode = (*doublyList);
    if((*doublyList) != NULL) {
        (*doublyList)->previousNode = newNode;
    }
    (*doublyList) = newNode;
}

void showDoublyList(doubleNode* doublyList) {
    doubleNode *currentNode = NULL;
    currentNode = doublyList;
    
    if(currentNode != NULL) {
        printf("\nElements in the list..............................................\n\n");
        while (currentNode != NULL) {
            printf("| %d | ", currentNode->data);
            currentNode = currentNode->nextNode;
        }
        printf("\n");
        printf("\nElements in the list..............................................\n\n");
        printf("\n");
    }
}

void doublyListToFile(doubleNode *doublyList, char file[], int limit) {
    FILE* myFile = fopen(file, "wb");
    int data;
    if(myFile) {
        while(doublyList) {
            if(doublyList->data > limit) {
                data = doublyList->data;
                fwrite(&data, sizeof(int), 1, myFile);
                
            }
            doublyList = doublyList->nextNode;
        }
        fclose(myFile);
    }
}

void showFileOfDoublyList(char file[]) {
    FILE* myFile = fopen(file, "rb");

    int data;

    if(myFile) {
        printf("\nReading File... ");
        printf("\n======================================");
        printf("\n");
        while(fread(&data, sizeof(int), 1, myFile) > 0) {
            printf("| %d |", data);
        }
        printf("\n======================================");

        fclose(myFile);
    }
}