#include<stdio.h>
#include<stdlib.h>

#include "ILinkedList.h"

node* initializeList() {
    return NULL;
}

node* createNode(person data) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->nextNode = NULL;
    return newNode;
}

node* insertAtFront(node *list, node *newNode) {
    if(list == NULL) {
        list = newNode;
    }
    else {
        newNode->nextNode = list;
        list = newNode;
    }
    return list;
}

void showNode(node *myNode) {
    showPerson(myNode->data);
}

void showList(node *list) {
    node *currentNode = list;
    while(currentNode != NULL) {
       showNode(currentNode);
       currentNode = currentNode->nextNode;
    }
}

node* searchNode(node *list) {
    node* searchNode = list;
    if(list != NULL) {
        while(searchNode->nextNode != NULL) {
            searchNode = searchNode->nextNode;
        }
    }
    return searchNode;
}

node* insertAtLast(node *list, node *newNode) {
    if(!list) {
        list = newNode;
    }
    else {
        node *lastNode = searchNode(list);
        lastNode->nextNode = newNode;
    }
    return list;
}
