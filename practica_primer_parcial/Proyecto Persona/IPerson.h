#ifndef IPERSON_H
#define IPERSON_H

typedef struct person {
    char name [20];
    char gender;
    int age;
}person;

person createPerson(void);
void showPerson(person );
int createPersonArray(person [], int );
void showPersonArray(person [], int );


#endif //IPERSON_H