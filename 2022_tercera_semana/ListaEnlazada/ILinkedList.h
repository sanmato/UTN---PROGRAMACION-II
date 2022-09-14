#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

#include "IPerson.h"

typedef struct node {
    person data;
    struct node *nextNode;
}node;

node* initializeList();
node* createNode(person );
node* insertAtFront(node * , node * );
void showNode(node * );
void showList(node * );
node* searchNode(node *);
node* insertAtLast(node *, node *);
node* insertInOrder(node *, node *);
int countElements(node *);
node* intercalateList(node *, node *, node *);
node* popFirst(node *);
node* reverseList(node *);

#endif //ILINKEDLIST_H