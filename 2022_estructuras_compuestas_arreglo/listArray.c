#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"IListArray.h"

int cargarNotas(celda arreglo[], int dimension) {
    int nota;
    char nombreAlumno[30];
    char nombreMateria[30];
    int validos = 0;
    char control = 's';

    while(validos < dimension && control == 's') {
        printf("\nIngrese nombre del alumno: ");
        fflush(stdin);
        gets(nombreAlumno);
        printf("\nIngrese la materia: ");
        fflush(stdin);
        gets(nombreMateria);
        printf("\nIngrese la nota: ");
        scanf("%d", &nota);
        validos = alta(arreglo, nombreMateria, nombreAlumno, nota, validos);
        printf("\nValidos 2: %d", validos);
        printf("\nDesea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return validos;
}

nodo* crearNodo(int nota, char nombreAlumno[]) {
    static int legajo = 0;
    legajo++;
    nodo* aCrear = (nodo*)malloc(sizeof(nodo));
    aCrear->dato.nota = nota;
    strcpy(aCrear->dato.nombre, nombreAlumno);
    aCrear->dato.legajo = legajo;
    aCrear->siguienteNodo = NULL;
    return aCrear;
}

int alta(celda arreglo[], char nombreMateria[], char nombreAlumno[], int nota, int validos) {
    nodo* auxiliar = crearNodo(nota, nombreAlumno);
    int materia = buscarMateria(arreglo, nombreMateria, validos);
    if(materia == -1) {
        validos = cargarMateria(arreglo, nombreMateria, validos);
        materia = validos-1;
    }
    arreglo[materia].listaDeNotas = insertarAlPrincipio(arreglo[materia].listaDeNotas, auxiliar);
    return validos;
}

int buscarMateria(celda arreglo[], char nombreMateria[], int validos) {
    int flag = -1;
    int i = 0;
    while(i<validos && flag == -1) {
        if(strcmp(arreglo[i].materia, nombreMateria) == 0) {
            flag = i;
        }
        i++;
    }
    return flag;
}

nodo* inicLista() {
    return NULL;
}

int cargarMateria(celda arreglo[], char nombreMateria[], int validos) {
    strcpy(arreglo[validos].materia, nombreMateria);
    arreglo[validos].listaDeNotas = inicLista();
    validos++;
    return validos;
}

nodo* insertarAlPrincipio(nodo* lista, nodo* nuevoNodo) {
    if(lista == NULL) {
        lista = nuevoNodo;
    } else {
        nuevoNodo->siguienteNodo = lista;
        lista = nuevoNodo;
    }
    return lista;
}

void mostrarNodo(notaAlumno miAlumno) {
    printf("\n Nombre del alumno : %s \n",miAlumno.nombre);
    printf("\n Legajo del alumno : %d \n",miAlumno.legajo);
    printf("\n Nota del alumno   : %d \n",miAlumno.nota);
}

void mostrarLista(nodo* lista) {
    nodo* temp = lista;
    while(temp) {
        mostrarNodo(temp->dato);
        temp = temp->siguienteNodo;
    }
}