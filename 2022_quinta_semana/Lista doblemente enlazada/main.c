#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"IDoublyLinkedList.h"

int main()
{
    char fileName[] = {"doublyList.bin"};
    doubleNode* doubleList;
    doubleList = initializeDoubleList();
    /*char name[] = {"santiagt"};

    if(name[strlen(name)-1] == 'o') {
        printf("\nHola perro");
    } else {
        printf("\nchupala loco");
    }*/

    doubleNode* node1 = NULL;
    doubleNode* node2 = NULL;

    node1 = createNode(1);
    node2 = createNode(12);

    insertAtFront(&doubleList, node1);
    insertAtFront(&doubleList, node2);

    showDoublyList(doubleList);

    doublyListToFile(doubleList, fileName, 10);

    showFileOfDoublyList(fileName);

    return 0;
}
