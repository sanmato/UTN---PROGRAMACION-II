#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"celda.h"

typedef struct registroArchivo {
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
}registroArchivo;


int cargaADL(celda[] ,int , char[] );
int alta(celda[], int , stMateria , stNotaAlumno );
int buscaPosMateria(celda[], int , int );
int agregarCelda(celda[], int , stMateria );
stMateria getMateria(registroArchivo );
stNotaAlumno getNotaAlumno(registroArchivo );
nodo* altaLDL(nodo* , stMateria , stNotaAlumno );
void mostrarArregloLista(celda[] , int );
void mostrarArchivo(char []);

int main()
{
    int validos = 0, dimension = 20;
    celda arregloDeListas[dimension];

    char nombreDeArchivo[] = {"registroArchivo.dat"};


    validos = cargaADL(arregloDeListas, dimension, nombreDeArchivo);

    mostrarArregloLista(arregloDeListas, validos);
    
    return 0;
}

int cargaADL(celda adl[], int dim, char nombreArchivo[]) {
    registroArchivo registro;
    stMateria materia;
    stNotaAlumno nota;
    FILE* archi = fopen(nombreArchivo, "rb");
    int validos = 0;
    if(archi) {
        while(validos<dim && fread(&registro,sizeof(registroArchivo),1,archi)>0) {
            materia = getMateria(registro);
            validos = alta(adl, validos, materia, getNotaAlumno(registro));
        }
        fclose(archi);
    }
    return validos;
}

int alta(celda adl[], int validos, stMateria materia, stNotaAlumno nota) {
    int posicion = buscaPosMateria(adl, validos, materia.idMateria);
    if(posicion == -1) {
        validos = agregarCelda(adl, validos, materia);
        posicion = validos-1;
        adl[posicion].listaDeNotas = inicLista();
    }
    adl[posicion].listaDeNotas = agregarAlFinal(adl[posicion].listaDeNotas, crearNodo(nota));
    return validos;
}

int buscaPosMateria(celda adl[], int validos, int id) {
    int i = 0;
    int flag = -1;
    while(i < validos && flag == -1) {
        if(adl[i].dato.idMateria == id) {
            flag = i;
        }
        i++;
    }
    return flag;
}

int agregarCelda(celda adl[], int validos, stMateria materia) {
    adl[validos].dato = materia;
    adl[validos].listaDeNotas = inicLista();
    validos++;
    return validos;
}

stMateria getMateria(registroArchivo registro) {
    stMateria miMateria;
    miMateria.idMateria = registro.idMateria;
    strcpy(miMateria.materia, registro.materia);

    return miMateria;
}

stNotaAlumno getNotaAlumno(registroArchivo registro) {
    stNotaAlumno nota;
    nota.legajo = registro.legajo;
    strcpy(nota.nombreApe, registro.nombreApe);
    nota.nota = registro.nota;

    return nota;
}

void mostrarArchivo(char nombreArchivo[]) {
    FILE* archi = fopen(nombreArchivo, "rb");

    registroArchivo registro;

    if(archi) {
        while(fread(&registro, sizeof(registroArchivo), 1, archi) > 0) {
            printf("\n %d", registro.nota);
            printf("\n %d", registro.legajo);
            printf("\n %s", registro.nombreApe);
            printf("\n %s", registro.materia);
            printf("\n %d", registro.idMateria);
        }
        fclose(archi);
    }
}

void mostrarArregloLista(celda adl[], int validos) {
    for(int i=0; i<validos; i++) {
        muestraUnaCelda(adl[i]);
    }
}

void materiasConInicial2Archivo(char nombreArchivo[], celda arreglo[], int val, char inicial)
{
    FILE* archi= fopen(nombreArchivo, "wb");
    registroArchivo a;

    if(archi)
    {
        for(int i=0; i<val; i++)
        { if(arreglo[i].dato.materia[0] == inicial)  //<=== EL IF VA ANTES
           {

             seg= arreglo[i].listaDeNotas;  //<====================
              while(seg)
               {
                    strcpy(a.materia, arreglo[i].dato.materia);
                    a.idMateria = arreglo[i].dato.idMateria;
                    strcpy(a.nombreApe, seg->nombreApe);
                    a.legajo = seg->legajo;
                    a.nota = seg->nota;
                    fwrite(&a, sizeof(registroArchivo), 1, archi);
                    seg=seg->siguiente;
            }
        }
    fclose(archi);
   }
