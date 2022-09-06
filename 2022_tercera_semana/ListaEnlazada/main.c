#include<stdio.h>
#include<stdlib.h>

#include"ILinkedList.h"

int main()
{
    node *listNode;
    node *myNode1;
    node *myNode2;
    node *myNode3;

    myNode1 = createNode(loadPerson());
    myNode2 = createNode(loadPerson());
    myNode3 = createNode(loadPerson());

    listNode = initializeList();
    listNode = insertAtFront(listNode, myNode1);
    listNode = insertAtFront(listNode, myNode2);
    listNode = insertAtLast(listNode, myNode3);

    printf("\nItems:");
    showList(listNode);

    return 0;
}
