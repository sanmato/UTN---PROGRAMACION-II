#include<stdio.h>
#include<stdlib.h>

//1
typedef struct {
    char name[30];
    char gender;
    int age;
}person;

// a) Crear un arreglo estático de 30 elementos de esta estructura y cargarlo mediante una función.
person loadPerson();
int loadPersonArray(person *, int );
void showPerson(person );
void showPersonArray(person *, int );
int genderCounter(person *, int , char );
void copyArray(person *, person *, int , char );
int copyArray2(person *fromArray, int elements, char gender, person **toArray);

int main()
{
    int dimension = 10, elements = 0, sameGender = 0, elementsPointer = 0;
    char gender;

    person myPersonArray[dimension];
    person *newArray = NULL;

    elements = loadPersonArray(myPersonArray, dimension);
    showPersonArray(myPersonArray, elements);

    printf("\nInsert gender to count m/f: ");
    fflush(stdin);
    scanf("%c", &gender);

    sameGender = genderCounter(myPersonArray, elements, gender);
    printf("\n%d %c elements in array", sameGender, gender);

    //copyArray(myPersonArray, newArray, elements, gender);

    elementsPointer = copyArray2(myPersonArray, elements, gender, &newArray);
    printf("\n%d", elementsPointer);
    showPersonArray(newArray, elementsPointer);

    printf("\n");
    system("pause");

    return 0;
}

person loadPerson(void) {
    person auxPerson;

    printf("\nInsert name: ");
    fflush(stdin);
    gets(auxPerson.name); 

    printf("\nInsert gender: ");
    fflush(stdin);
    scanf("%c", &auxPerson.gender);

    printf("\nInsert edad: ");
    fflush(stdin);
    scanf("%d", &auxPerson.age);

    return auxPerson;
}

int loadPersonArray(person *personArray, int dimension) {
    int elements = 0;
    char control = 'y';

    while (control == 'y' && elements < dimension) {
        personArray[elements] = loadPerson();

        printf("\nDo you wish to load more elements? y/n: ");
        fflush(stdin);
        scanf("%c", &control);
        elements++;
    }
    return elements;
}

void showPerson(person personParam) {
    printf("\n------------------------------");
    printf("\n\tName: %s\t", personParam.name);
    printf("\n\tGender: %c\t", personParam.gender);
    printf("\n\tAge: %d\t", personParam.age);
    printf("\n------------------------------"); 
}

void showPersonArray(person *personArray, int elements) {
    int iterator;
    for(iterator = 0; iterator < elements; iterator++) {
        showPerson(personArray[iterator]);
    }
}

int genderCounter(person *personArray, int elements, char genderToCount) {
    int genderCounter = 0, iterator;

    for (iterator = 0; iterator < elements; iterator++) {
        if(personArray[iterator].gender == genderToCount) {
            genderCounter++;
        }
    }
    return genderCounter;
}

void copyArray(person *fromArray, person *toArray, int elements, char genderToCopy) {
    int totalGender = 0;
    
    totalGender = genderCounter(fromArray, elements, genderToCopy);

    toArray = (person *)malloc(sizeof(person)*totalGender);

    int i = 0, j = 0;
    while(i < elements) {
        if(fromArray[i].gender == genderToCopy) {
            toArray[j] = fromArray[i];
            showPerson(toArray[j]);
            j++;
        }
        i++;
    }
}

int copyArray2(person *fromArray, int elements, char gender, person **toArray) {
    int totalGender = genderCounter(fromArray, elements, gender);
    (*toArray) = (person*)malloc(sizeof(person)*totalGender);
    int i, j=0;
    printf("\nvalidos: %d", elements);
    printf("\nTotalgender: %d", totalGender);
    for(i = 0; i < elements; i++) {
        if(fromArray[i].gender == gender) {
            (*toArray)[j] = fromArray[i];
            //showPerson(fromArray[i]);
            j++;
        }
    }
    return j;
}

 