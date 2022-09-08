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

node* insertInOrder(node *list, node *newNode) {
    if(!list) {
        list = newNode;
    } else {
        if(newNode->data.age < list->data.age) {
            list = insertAtFront(list, newNode);
        } else {
            node *prevNode = list;
            node *currentNode = list->nextNode;

            while((currentNode != NULL) && newNode->data.age > currentNode->data.age) {
                prevNode = currentNode;
                currentNode = currentNode->nextNode;
            }
            prevNode->nextNode = newNode;
            newNode->nextNode = currentNode;
        }
    }
    return list;
}

int countElements(node *list) {
    int counter = 0;
    if(list) {
        counter = countElements(list->nextNode);
        counter++;
    }
    return counter;
}

node* intercalateList(node *firstList, node *secondList, node *newList) {

    node *temp = NULL;

    while(firstList && secondList) {
        if(firstList->data.age < secondList->data.age) {
            temp = firstList;
            firstList = firstList->nextNode;
        } else {
            temp = secondList;
            secondList = secondList->nextNode;
        }
        temp->nextNode = NULL;
        newList = insertAtLast(newList, temp);
    }
    while(firstList) {
        temp = firstList;
        firstList = firstList->nextNode;
        temp->nextNode = NULL;
        newList = insertAtLast(newList, temp);
    } while(secondList) {
        temp = secondList;
        secondList = secondList->nextNode;
        temp->nextNode = NULL;
        newList = insertAtLast(newList, temp);
    }

    return newList;
}