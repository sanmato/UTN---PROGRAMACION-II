#include<stdlib.h>
#include<stdio.h>

#include "ILinkedList.h"

int main()
{
    node* aList;
    node* mynode1 = NULL;
    node* mynode2 = NULL;
    node* mynode3 = NULL;

    aList = initializeList();

    mynode1 = createNode(4);
    mynode2 = createNode(5);

    insertAtLast(&aList, mynode1);
    insertAtLast(&aList, mynode2);

    showList(aList);

    system("pause");

    
    return 0;
}
