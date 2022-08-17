#ifndef IEMPLOYEE_H
#define IEMPLOYEE_H

typedef struct {
  int id;
  char name[25];
  char lastName[25];
  int age;
}employee;

employee loadEmployee();
void showEmployee(employee);


#endif //IEMPLOYEE_H