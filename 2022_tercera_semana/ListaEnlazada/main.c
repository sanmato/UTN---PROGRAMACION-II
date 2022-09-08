#include<stdio.h>
#include<stdlib.h>

#include"ILinkedList.h"

int main()
{
    node *listNode, *anotherListNode, *newListNode;
    node *myNode1;
    node *myNode2;
    node *myNode3;
    node *myNode4;
    node *myNode5;
    node *myNode6;
    node *myNode7;
    int count = 0;

    myNode1 = createNode(loadPerson());
    myNode2 = createNode(loadPerson());
    myNode3 = createNode(loadPerson());
    myNode4 = createNode(loadPerson());
    myNode5 = createNode(loadPerson());
    myNode6 = createNode(loadPerson());
    myNode7 = createNode(loadPerson());

    listNode = initializeList();
    anotherListNode = initializeList();
    newListNode = initializeList();
    listNode = insertInOrder(listNode, myNode1);
    listNode = insertInOrder(listNode, myNode2);
    listNode = insertInOrder(listNode, myNode3);

    anotherListNode = insertInOrder(anotherListNode, myNode4);
    anotherListNode = insertInOrder(anotherListNode, myNode5);
    anotherListNode = insertInOrder(anotherListNode, myNode6);
    anotherListNode = insertInOrder(anotherListNode, myNode7);

    showList(listNode);

    system("pause");

    showList(anotherListNode);

    system("pause");

    newListNode = intercalateList(listNode, anotherListNode, newListNode);

    showList(newListNode);

   /* count = countElements(listNode);

    printf("\n%d elements", count);

    printf("\nItems:");
    showList(listNode);*/

    



    return 0;
}
