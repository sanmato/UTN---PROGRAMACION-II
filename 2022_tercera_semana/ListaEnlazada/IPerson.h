#ifndef IPERSON_H
#define IPERSON_H

typedef struct {
    char name[20];
    int age;
    char gender;
}person;

person loadPerson();
void showPerson(person );

#endif //IPERSON_H