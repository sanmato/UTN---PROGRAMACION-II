#include<stdio.h>
#include<stdlib.h>

#include"ILinkedList.h"

node* initializeList() {
    return NULL;
}

node* createNode(person data) {
    node* tempNode = NULL;
    tempNode = (node*)malloc(sizeof(node));
    tempNode->data = data;
    tempNode->nextNode = NULL;

    return tempNode;
}

node* insertAtFront(node* list, node* newNode) {
    if(!list) {
        list = newNode;
    } else {
        newNode->nextNode = list;
        list = newNode;
    }
    return list;
}

void showList(node* list) {
    node* currentNode = list;
    if(list) {
        while(currentNode) {
            showPerson(currentNode->data);
            currentNode = currentNode->nextNode;
        }
    } else {
        printf("\nEmpty...");
    }
}

node* searchLastNode(node* list) {
    node* searchingNode = list;

    if(list) {
        while(searchingNode->nextNode != NULL) {
            searchingNode = searchingNode->nextNode;
        }
    }
    return searchingNode;
}

node* insertAtLast(node* list, node* newNode) {
    if(list) {
        node* lastNode = searchLastNode(list);
        lastNode->nextNode = newNode;
    }
    return list;
}

node* insertInOrderByAge(node* list, node* newNode) {
    if(!list) {
        list = newNode;
    } else {
        if(newNode->data.age < list->data.age) {
            list = insertAtFront(list, newNode);
        } else {
            node* previousNode = list;
            node* toCompare = list->nextNode;

            while((toCompare) && (newNode->data.age > toCompare->data.age)) {
                previousNode = toCompare;
                toCompare = toCompare->nextNode;
            }
            previousNode->nextNode = newNode;
            newNode->nextNode = toCompare;
        }
    }
    return list;
}

node* intercalateList(node* firstList, node* secondList, node* newList) {
    node* temp = NULL;

    while(firstList && secondList) {
        if(firstList->data.age < firstList->data.age) {
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
        } else
        if(secondList) {
            temp = secondList;
            secondList = secondList->nextNode;
        }
        temp->nextNode = NULL;
        newList = insertAtLast(newList, temp);
    }
    return newList;
}

void showReverseList(node* list) {
    if(list) {
        showReverseList(list->nextNode);
        showPerson(list->data);
    }
}

node* deleteFirst(node* list) {
    node* toDelete = list;

    list = list->nextNode;
    free(toDelete);

    return list;
}

node* deleteLast(node* list) {
    node* toDelete = searchLastNode(list);
    node* searchNode = list;
    while(searchNode->nextNode != toDelete) {
        searchNode = searchNode->nextNode;
    }
    searchNode->nextNode = NULL;
    free(toDelete);
    return list;
}

node* deleteNodeAtPosByAge(node* list, int age) {
    if((list) && (list->data.age == age)) {
        list = deleteFirst(list);
    } else {
        node* previousNode = list;
        node* temp = list->nextNode;

        while((temp) && (temp->data.age != age)) {
            previousNode = temp;
            temp = temp->nextNode;
        }

        if(temp) {
            previousNode->nextNode = temp->nextNode;
            free(temp);
        }
    }
    return list;
}

int countElements(node* list) {
    int elements = 0;
    node* currentNode = list;
    while(currentNode) {
        currentNode = currentNode->nextNode;
        elements++;
    }
    return elements;
}

person peek(node* list) {
    if(list) {
        return list->data;
    } else {
        printf("\nEmpty...");
    }
}

int listToArray(node* list, person personArray[], int dimension) {
    int elements = 0;
    node* currentNode = list;
    while((list) && (elements < dimension)) {
        personArray[elements] = currentNode->data;
        currentNode = currentNode->nextNode;
        elements++;
    }
    return elements;
}

node* arrayToList(person personArray[], int elements) {
    node* temp = NULL;
    node* list = initializeList();
    node* first = NULL;

    first = createNode(personArray[0]);
    list = insertAtFront(list, first);

    for(int i=1; i < elements; i++) {
        temp = createNode(personArray[i]);
        list = insertAtLast(list, temp);
    }
    return list;
}