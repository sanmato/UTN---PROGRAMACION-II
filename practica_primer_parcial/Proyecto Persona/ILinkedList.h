#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

#include "IPerson.h"

typedef struct node {
    person data;
    struct node *nextNode;
}node;

node *initializeList(void);
node *createNode(person );
node *insertAtFront(node* , node * );
void showList(node* );
node *searchLastNode(node* );
node *insertAtLast(node *, node *);
node *insertInOrderByAge(node *, node *);
node *intercalateList(node *, node *, node *);
void showReverseList(node *);
node *deleteFirst(node *);
node *deleteLast(node *);
node *deleteNodeAtPosByAge(node *, int );
int countElements(node *);
person peek(node* );
int listToArray(node *, person [], int );
node* arrayToList(person [], int );
void listToFile(node *, char []);
node* fileToList(char [], node *, int );
void showFileData(char []);

#endif //ILINKEDLIST_H