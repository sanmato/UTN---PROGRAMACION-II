#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"IListArray.h"

int main()
{
    celda arreglo[20];
    char nombreMateria[30];
    int validos = 0;
    validos = cargarNotas(arreglo, 20);
    printf("\nIngrese la materia que desea mostrar: ");
    fflush(stdin);
    gets(nombreMateria);

    int pos = buscarMateria(arreglo, nombreMateria, validos);
    if(pos != -1) {
        mostrarLista(arreglo[pos].listaDeNotas);
    }

    return 0;
}
