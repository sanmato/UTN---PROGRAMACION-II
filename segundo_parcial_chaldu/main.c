#include<stdio.h>
#include<stdlib.h>

typedef struct stRegistroVendedor{
    int idSector,
    char sector[30];
    int dni;
    char nombreYapellido[40];
    int ventasDiarias;
}stRegistroVendedor;

typedef struct stSector {  //ESTA HABIA QUE DEFINIRLA
    int idSector;
    char sector[30];
}stSector;

typedef struct stVendedor { //ESTA HABIA QUE DEFINIRLA
    int dni;
    char nombreYapellido[40];
    int ventasDiarias;
}stVendedor;

typedef struct nodoArbol {
    stVendedor dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

typedef struct celda {
    stSector sector;
    nodoArbol* arbolVendedores;
}celda;

/*Ejercicio 1*/
int pasarArchivoToADA(celda arreglo[], int dimension) {
    int validos = 0;
    FILE* buffer = fopen("archivoRegistrosVendedor.bin", "rb");

    stRegistroVendedor aux;

    if(buffer) {
        while(validos < dimension && fread(&aux, sizeof(stRegistroVendedor), 1, buffer) > 0) {
            validos = alta(arreglo, validos, aux);
        }
        fclose(buffer);
    }
    return validos;
}

int alta(celda arreglo[], int validos, stRegistroVendedor aux) {
    int pos = buscarPosicion(arreglo, validos, aux.idSector);
    if(pos == -1) {
        validos = agregarSector(arreglo, validos, aux.idSector, aux.sector);
        pos = validos-1;
    }
    nodoArbol* nuevo = crearNodoArbol(aux);
    arreglo[pos].arbolVendedores = insertarNodo(arreglo[pos].arbolVendedores, nuevo);

    return validos;
}

nodoArbol* crearNodoArbol(stRegistroVendedor aux) {
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = cargarDatoArbol(aux);
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

stVendedor cargarDatoArbol(stRegistroVendedor aux) {
    stVendedor nuevo;
    nuevo.dni = aux.dni;
    strcpy(nuevo.nombreYapellido, aux.nombreYapellido);
    nuevo.ventasDiarias = aux.ventasDiarias;

    return nuevo;
}

int buscarPosicion(celda arreglo[], int validos, int idSector) {
    int pos = -1;
    int i = 0;
    while(i<validos && pos == -1) {
        if(arreglo[i].sector.idSector == idSector) {
            pos = i;
            i++;
        }
    }
    return pos;
}

int agregarSector(celda arreglo[], int validos, int idSector, char sector[]) {
    arreglo[validos].sector.idSector = idSector;
    strcpy(arreglo[validos].sector.sector = sector);
    arreglo[validos].arbolVendedores = inicArbol();

    return validos;
}

nodoArbol* inicArbol() {
    return NULL;
}

nodoArbol* insertarNodo(nodoArbol* arbol, nodoArbol* nuevo) {
    if(!arbol) {
        arbol = nuevo;
    } else {
        if(nuevo->dato.dni > arbol->dato.dni) {
            arbol->der = insertarNodo(arbol->der, nuevo);
        } else {
            arbol->izq = insertarNodo(arbol->izq, nuevo);
        }
    }

    return arbol;
}

void mostrarADA(celda arreglo[], int validos) {
    int i = 0;
    while(i < validos) {
        printf("------------------------------------------\n");
        printf("Sector %s (ID %i) \n", arreglo[i].sector.sector, arreglo[i].sector.idSector);
        printf("------------------------------------------\n");
        printf("------------------------------------------\n");
        inorder(arreglo[i].arbolVendedores);
        i++;
    }
}

void inorder(nodoArbol* arbol) {
    if(arbol) {
        inorder(arbol->izq);
        mostrarVendedor(arbol->dato);
        inorder(arbol->der);
    }
}

mostrarVendedor(stVendedor aux) {
    printf("DNI: %i\n", aux.dni);
    printf("Nombre y Apellido: %s\n", aux.nombreYapellido);
    printf("Ventas Diarias: $%d\n", aux.ventasDiarias);
    printf("------------------------------------------\n");
}

nodoArbol* buscarVendedorArreglo(celda arreglo[], int validos, int dni) {
    int i = 0;
    nodoArbol* buscado = NULL;

    while(i<validos && !buscado) {
        buscado = buscarVendedorArbol(arreglo[i].arbolVendedores, dni);
        i++;
    }
    return buscado;
}

nodoArbol* buscarVendedorArbol(nodoArbol* arbol, int dni) {
    nodoArbol* buscado = NULL;

    if(arbol) {
        if(dni == arbol->dato.dni) {
            buscado = arbol;
        }
        else {
            if(dni > arbol->dato.dni) {
                buscado = buscarVendedorArbol(arbol->der, dni);
            } else {
                buscado = buscarVendedorArbol(arbol->izq, dni);
            }
        }
    }
    return buscado;
}


int cantidadVendedoresSuperiores(celda arreglo[], int validos, int idSector, int ventas) {
    int pos = buscarPosicion(arreglo, validos, idSector);

    if(pos != -1) {
        int cantidad = cantidadVendedoresSuperioresSector(arreglo[pos].arbolVendedores, ventas);
        return cantidad;
    } else {
        return -1;
    }
}

int cantidadVendedoresSuperioresSector(nodoArbol* arbol, int ventas) {
    int rta = 0;
    if(arbol == NULL) {
        rta = 0;
    } else {
        if(arbol->dato.ventasDiarias > ventas) {
            rta = 1 + cantidadVendedoresSuperioresSector(arbol->izq, ventas) + cantidadVendedoresSuperioresSector(arbol->der, ventas);
        } else {
            rta = cantidadVendedoresSuperioresSector(arbol->izq, ventas) + cantidadVendedoresSuperioresSector(arbol->der, ventas);
        }
    }
    return rta;
}

int sectorMasVentas(celda arreglo[], int validos) {
    int i =0;
    int ventas = 0;
    int mayor = 0;
    int idSector = 0;

    while(i<validos) {
        ventas = sumarVentasSector(arreglo[i].arbolVendedores);
        if(ventas > mayor) {
            mayor = ventas;
            idSector = arreglo[i].sector.idSector;
        }
        i++;
    }
    return idSector;
}

int sumarVentasSector(nodoArbol* arbol) {
    int rta;
    if(arbol == NULL) {
        rta = 0;
    } else {
        rta = arbol->dato.ventasDiarias + sumarVentasSector(arbol->izq) + sumarVentasSector(arbol->der);
    }
    return rta;
}

float porcentajeVentas(celda arreglo[], int validos, int idSector) {
    int pos = buscarPosicion(arreglo, validos, idSector);

    if(pos != -1) {
        int ventasSector = sumarVentasSector(arreglo[pos].arbolVendedores);
        int ventasTotales = calcularVentasTotales(arreglo, validos);
        float porcentaje = (float) (ventasSector * 100) /ventasTotales;
        return porcentaje;
    } else {
        return -1;
    }
}

int calcularVentasTotales(celda arreglo[], int validos) {
    int i = 0;
    int total = 0;

    while(i < validos) {
        total += sumarVentasSector(arreglo[i].arbolVendedores);
        i++;
    }
    return total;
}

int main()
{
    
    return 0;
}







