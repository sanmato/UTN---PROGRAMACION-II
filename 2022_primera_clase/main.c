#include<stdio.h>
#include<stdlib.h>

#include"IEmployeeStack.h"

//Por que esta función en el main y no en la libreria de pilas?
//Porque esta función no es inherente a una pila.
//Es decir, no es un comportamiento base de la pila el tener que cargarse en un archivo.
void stackToFile(char fileName[], employeeStack *stack);
void showFile(char filename[]);

int main()
{
    employeeStack stack;
    char fileName[] = {"stack.txt"};
    initializeEmployeeStack(&stack);

    readWithLimit(&stack);

    showStack(&stack);

    stackToFile(fileName, &stack);

    showFile(fileName);
    
    return 0;
}


void stackToFile(char fileName[], employeeStack *stack) {
    FILE* myFile = fopen(fileName, "w+");

    employeeStack auxStack;
    initializeEmployeeStack(&auxStack);

    if(myFile != NULL) {
        fwrite(stack, sizeof(employeeStack), 1, myFile);
        fclose(myFile);
    } else {
        printf("File can't be opened");
    }
}

void showFile(char fileName[]) {
    FILE *myFile = fopen(fileName, "r");
    employeeStack myEmployeeStack;

    if(myFile != NULL) {
        printf("\n======================================");
        printf("\nReading File... ");
        while(fread(&myEmployeeStack, sizeof(employeeStack), 1, myFile) > 0) {
            showStack(&myEmployeeStack);
        }
        printf("\n======================================");
        fclose(myFile);
    }
}
