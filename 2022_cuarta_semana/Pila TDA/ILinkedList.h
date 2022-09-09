#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

typedef struct node {
    int data;
    struct node *nextNode;
}node;

node* initializeList();
node* createNode(int );
node* insertAtFront(node * , node * );
node* pushFront(node *);
void showList(node * );
node* searchNode(node *);
node* insertAtLast(node *, node *);
node* insertInOrder(node *, node *);
int countElements(node *);
node* intercalateList(node *, node *, node *);
node* popFirst(node *);

#endif //ILINKEDLIST_H