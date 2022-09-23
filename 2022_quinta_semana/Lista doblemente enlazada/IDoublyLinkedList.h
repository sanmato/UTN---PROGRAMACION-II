#ifndef IDOUBLYLINKEDLIST_H
#define IDOUBLYLINKEDLIST_H

typedef struct doubleNode {
    int data;
    struct doubleNode* previousNode;
    struct doubleNode* nextNode;
} doubleNode;

doubleNode* initializeDoubleList(void);
doubleNode* createNode(int );
void insertAtFront(doubleNode **, doubleNode *);
void showDoublyList(doubleNode *);
void doublyListToFile(doubleNode *, char [], int );
void showFileOfDoublyList(char []);


#endif //IDOUBLYLINKEDLIST_H