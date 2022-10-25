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

doubleNode* insertAtFront(doubleNode* doublyList, doubleNode* newNode) {
    newNode->nextNode = doublyList;
    if(doublyList != NULL) {
        doublyList->previousNode = newNode;
    }
    return doublyList;
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

int peek(doubleNode* doublyList) {
    int info;
    if(doublyList) {
        info = doublyList->data;
    }
    return info;
}

doubleNode* pop(doubleNode* doublyList) {
    doubleNode* temp = doublyList;
    if(doublyList) {
        doublyList = doublyList->nextNode;
        if(doublyList) {
            doublyList->previousNode = NULL;
        }
        free(temp);
    }
    return doublyList;
}

doubleNode* searchLastNode(doubleNode* doublyList) {
    if(doublyList) {
        while(doublyList->nextNode != NULL) {
            doublyList = doublyList->nextNode;
        }
    }
    return doublyList;
}

doubleNode* insertAtLast(doubleNode* doublyList, doubleNode* newNode) {
    if(!doublyList) {
        doublyList = newNode;
    } else {
        doubleNode* last = searchLastNode(doublyList);
        newNode->previousNode = last;
        last->nextNode = newNode;
    }
    return doublyList;
}

doubleNode* deleteNode(doubleNode* doublyList, int toDelete) {
    if(!doublyList) {
        printf("\nEmpty...");
    }

    if(doublyList->data == toDelete) {
        doublyList = pop(doublyList);
    }

    if()

    return doublyList;
}