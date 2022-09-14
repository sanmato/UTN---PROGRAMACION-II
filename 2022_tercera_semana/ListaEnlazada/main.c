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
    /*myNode4 = createNode(loadPerson());
    myNode5 = createNode(loadPerson());
    myNode6 = createNode(loadPerson());
    myNode7 = createNode(loadPerson());*/

    listNode = initializeList();
    anotherListNode = initializeList();
    newListNode = initializeList();
    listNode = insertAtFront(listNode, myNode1);
    listNode = insertAtFront(listNode, myNode2);
    listNode = insertAtFront(listNode, myNode3);

    /*anotherListNode = insertInOrder(anotherListNode, myNode4);
    anotherListNode = insertInOrder(anotherListNode, myNode5);
    anotherListNode = insertInOrder(anotherListNode, myNode6);
    anotherListNode = insertInOrder(anotherListNode, myNode7);*/

    //newListNode = intercalateList(listNode, anotherListNode, newListNode);

    //showList(newListNode);

   /* count = countElements(listNode);
    showList(listNode);*/

    showList(listNode);

    listNode = reverseList(listNode);

    showList(listNode);

    



    return 0;
}
