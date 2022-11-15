#include <stdio.h>
#include <stdlib.h>
#include "listaDeLista.h"

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
} registroArchivo;

#define NOMBRE_ARCHIVO "registroArchivo.dat"

notaAlumno GetNota(registroArchivo  r);

stMateria  GetMateria(registroArchivo  r);

listaDeLista * altaLDL(listaDeLista * ldl,stMateria materia,notaAlumno nota);

listaDeLista * CargaLDL(listaDeLista * lista,char NombreArchi[]);

void MuestraUnRegistroArchi(registroArchivo r);

void MostrarArchivo(char NombreArchi[]);



int main()
{
    listaDeLista * ldl = NULL;

    ldl = CargaLDL(ldl,NOMBRE_ARCHIVO);

    MostrarArchivo(NOMBRE_ARCHIVO);

    MuestraListaLista(ldl);

    return 0;
}


notaAlumno GetNota(registroArchivo  r)
{
    notaAlumno nota;
    nota.legajo = r.legajo;
    strcpy(nota.nombreApe, r.nombreApe);
    nota.nota = r.nota;
    return nota;
}

stMateria GetMateria(registroArchivo r)
{
    stMateria m;
    m.idMateria = r.idMateria;
    strcpy(m.materia, r.materia);
    return m;
}

listaDeLista * altaLDL(listaDeLista * ldl,stMateria materia,notaAlumno nota)
{
    listaDeLista * nuevo   = CrearNodoListaLista(materia);

    listaDeLista * buscado = BuscarMateriaListaLista(ldl,materia.idMateria);

    if(!buscado)
    {
        ldl = agregarAlPrincipioListaLista(ldl,nuevo);

        buscado = nuevo;
    }

    buscado->listaDeNotas = agregarAlPrincipioLista(buscado->listaDeNotas,crearNodoLista(nota));

    return ldl;
}

listaDeLista * CargaLDL(listaDeLista * ldl,char nombreArchi[])
{
    registroArchivo r;

    FILE * archi = fopen(nombreArchi,"rb");

    if(archi)
    {

        while(fread(&r,sizeof(registroArchivo),1,archi)>0)
        {
            ldl = altaLDL(ldl,GetMateria(r),GetNota(r));
        }
    }

    fclose(archi);

    return ldl;
}

void MuestraUnRegistroArchi(registroArchivo r)
{
    printf("\nNota---------%i",r.nota);
    printf("\nLegajo-------%i",r.legajo);
    printf("\nNombreYApe---%s",r.nombreApe);
    printf("\nMateria------%s",r.materia);
    printf("\nidMateria----%i\n",r.idMateria);
}

void MostrarArchivo(char nombreArchi[])
{
    FILE * archi = fopen(nombreArchi,"rb");

    registroArchivo r;

    while(fread(&r,sizeof(registroArchivo),1,archi)> 0)
    {
        MuestraUnRegistroArchi(r);
    }
}
