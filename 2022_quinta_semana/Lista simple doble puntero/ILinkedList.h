#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

typedef struct node {
    int data;
    struct node *nextNode;
}node;

node* initializeList();
node* createNode(int );
void insertAtFront(node ** , node * );
void showList(node * );
node* searchNode(node *);
void insertAtLast(node **, node *);
node* insertInOrder(node *, node *);
int countElements(node *);
node* intercalateList(node *, node *, node *);
node* popFirst(node *);
int peek(node *);

#endif //ILINKEDLIST_H