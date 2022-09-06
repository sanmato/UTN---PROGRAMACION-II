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

#endif //ILINKEDLIST_H