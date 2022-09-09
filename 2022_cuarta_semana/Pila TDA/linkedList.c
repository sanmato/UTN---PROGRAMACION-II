#include<stdio.h>
#include<stdlib.h>

#include "ILinkedList.h"

node* initializeList() {
    return NULL;
}

node* createNode(int data) {
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

node* pushFront(node* list) {
    node* newListNode;
    int data;

    printf("\nInsert element: ");
    scanf("%d", &data);

    newListNode = createNode(data);

    list = insertAtFront(list, newListNode);

    return list;
}


void showList(node* list) {
    node *currentNode;
    currentNode = list;
    if(currentNode != NULL) {
        printf("\nElements in the list..............................................\n\n");
        do {
            printf("| %d ", currentNode->data);
            currentNode = currentNode->nextNode;
        }
        while(currentNode != NULL);
        printf("\n");
        printf("\nElements in the list..............................................\n\n");
        printf("\n");
    }
    else {
        printf("List is empty!\n");
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
        if(newNode->data < list->data) {
            list = insertAtFront(list, newNode);
        } else {
            node *prevNode = list;
            node *currentNode = list->nextNode;

            while((currentNode != NULL) && newNode->data > currentNode->data) {
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
        if(firstList->data < secondList->data) {
            temp = firstList;
            firstList = firstList->nextNode;
        } else {
            temp = secondList;
            secondList = secondList->nextNode;
        }
        temp->nextNode = NULL;
        newList = insertAtLast(newList, temp);
    }
    while(firstList || secondList) {
        if(firstList) {
            temp = firstList;
            firstList = firstList->nextNode;
        } else if(secondList) {
            temp = secondList;
            secondList = secondList->nextNode;
        }
        temp->nextNode = NULL;
        newList = insertAtLast(newList, temp);
    }
    return newList;
}

node* popFirst(node *list) {
    node* temp = list;
    list = list->nextNode;
    free(temp);

    return list;
}