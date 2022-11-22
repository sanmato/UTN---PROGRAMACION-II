#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"celda.h"

typedef struct registroArchivo {
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
}registroArchivo;

#define NOMBRE_ARCHIVO "registroArchivo.dat"

int cargaADL(celda adl[], int dimension, char nombreArchivo) {
    FILE* archi = fopen(nombreArchivo, "rb");
    int validos = 0;
    registroArchivo buffer;

    stMateria auxMateria;
    stNotaAlumno auxNota;

    if(archi) {
        

        while(validos < dimension && fread(&buffer, sizeof(registroArchivo), 1, archi) > 0) {
            auxMateria = getMateria(buffer);
            auxNota = getNotaAlumno(buffer);
            validos = alta(adl, validos, auxNota, auxMateria);
        }

        fclose(archi);
    }

    return validos;
}



stMateria getMateria(registroArchivo r) {
    stMateria m;
    m.idMateria = r.idMateria;
    strcpy(m.materia, r.materia);

    return m;
}

stNotaAlumno getNotaAlumno(registroArchivo r) {
    stNotaAlumno n;
    n.legajo = r.legajo;
    n.nota = r.nota;
    strcpy(n.nombreApe, r.nombreApe);

    return n;
}

int alta(celda adl[], int validos, stMateria materia, stNotaAlumno nota) {
    int pos = buscaPosMateria(adl, validos, materia.idMateria);
    if(pos == -1) {
        validos = agregarCelda(adl, validos, materia);
        pos = validos-1;
    }
    adl[pos].listaDeNotas = agregarAlFinalD(adl[pos].listaDeNotas, crearNodoD(nota));
    return validos;
}

int buscaPosMateria (celda adl[], int validos, int id) {
    int flag = -1;
    int i = 0;
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
    adl[validos].listaDeNotas = inicListaD();
    validos++;

    return validos;
}



int main()
{
    return 0;
}
