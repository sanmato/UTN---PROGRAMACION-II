#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"

nodoArbol* archiToArbol(nodoArbol* arbol, char nombreArchivo[]) {
    FILE* archi = fopen(nombreArchivo, "rb");

    stPersona p;

    if(archi) {
        while(fread(&p, sizeof(stPersona), 1, archi) > 0) {
            arbol = agregarNodoArbol(arbol, p);
        }
        fclose(archi);
    }
    return arbol;
}

int main()
{
    nodoArbol* arbol;
    arbol=inicArbol();

    arbol = archiToArbol(arbol, "personas.dat");

    inOrden(arbol);

    arbol = borrarNodo(arbol, 9);
    inOrden(arbol);



    return 0;
}