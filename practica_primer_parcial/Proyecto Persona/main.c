#include<stdio.h>
#include<stdlib.h>

#include"ILinkedList.h"

int main()
{
    person newPerson = createPerson();
    person newPerson2 = createPerson();
    person newPerson3 = createPerson();
    node* node1 = createNode(newPerson);
    node* node2 = createNode(newPerson2);
    node* node3 = createNode(newPerson3);
    node* listNode = initializeList();
    listNode = insertInOrderByAge(listNode, node1);
    listNode = insertInOrderByAge(listNode, node2);
    listNode = insertInOrderByAge(listNode, node3);
    showList(listNode);
    printf("\n-----------------------------------------------");
    showReverseList(listNode);
    //listNode = deleteNodeAtPosByAge(listNode, 32);
    printf("\n-----------------------------------------------");
    showList(listNode);
    int elements = countElements(listNode);
    printf("\nElements: %d", elements);
    person peekedPerson = peek(listNode);
    showPerson(peekedPerson);

    node* emptyList = initializeList();
    int dimension = 3, elements2 = 0;
    person persons[dimension];
    elements2 = createPersonArray(persons, dimension);
    emptyList = arrayToList(persons, elements2);
    showList(emptyList);

    return 0;
}
