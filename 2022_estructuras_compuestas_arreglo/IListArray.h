#ifndef ILISTARRAY_H
#define ILISTARRAY_H

typedef struct registroArchivo {
    int nota;
    int legajo;
    char nombre[30];
    char materia[30];
    int idMateria;
}registroArchivo;

typedef struct notaAlumno {
    int nota;
    int legajo;
    char nombre[30];
}notaAlumno;

typedef struct nodo {
    notaAlumno dato;
    struct nodo* siguienteNodo;
}nodo;

typedef struct celda {
    int idMateria;
    char materia[30];
    nodo* listaDeNotas;
}celda;

int cargarNotas(celda [], int );
nodo* crearNodo(int , char[] );
int alta(celda [],char [], char [], int , int );
int cargarMateria(celda [], char [], int );
int buscarMateria(celda [], char [], int );
nodo* inicLista();
nodo* insertarAlPrincipio(nodo* , nodo* );
void mostrarNodo(notaAlumno );
void mostrarLista(nodo* );


#endif //ILISTARRAY_H