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
int peek(doubleNode *);
void pop(doubleNode **);
doubleNode* searchLastNode(doubleNode* );
void insertAtLast(doubleNode **, doubleNode *);

#endif //IDOUBLYLINKEDLIST_H