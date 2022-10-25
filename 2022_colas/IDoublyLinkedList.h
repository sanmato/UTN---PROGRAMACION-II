#ifndef IDOUBLYLINKEDLIST_H
#define IDOUBLYLINKEDLIST_H

typedef struct doubleNode {
    int data;
    struct doubleNode* previousNode;
    struct doubleNode* nextNode;
} doubleNode;

doubleNode* initializeDoubleList(void);
doubleNode* createNode(int );
doubleNode* insertAtFront(doubleNode *, doubleNode *);
void showDoublyList(doubleNode *);
void doublyListToFile(doubleNode *, char [], int );
void showFileOfDoublyList(char []);
int peek(doubleNode *);
doubleNode* pop(doubleNode *);
doubleNode* searchLastNode(doubleNode* );
doubleNode* insertAtLast(doubleNode *, doubleNode *);
doubleNode* deleteNode(doubleNode *, int );

#endif //IDOUBLYLINKEDLIST_H