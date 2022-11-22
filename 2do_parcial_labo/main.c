#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"celda.h"
#include"registroArchivo.h"

int agregarCelda(celda adl[], int validos, stEspecialidadMedica especialidad) {
    adl[validos].dato = especialidad;
    adl[validos].lista = iniciLista();
    validos++;

    return validos;
}

int buscaPosEspecialidad(celda adl[], int validos, int id) {
    int flag = -1;
    int i = 0;
    while(i<validos && flag == -1) {
        if(adl[i].dato.idEspecialidad == id) {
            flag = i;
        }
        i++;
    }
    return flag;
}

int alta(celda adl[], int validos, stEspecialidadMedica especialidad, stPaciente paciente) {
    int pos = buscaPosEspecialidad(adl, validos, especialidad.idEspecialidad);

    if(pos == -1) {
        validos = agregarCelda(adl, validos, especialidad);
        pos = validos-1;
    }

    adl[pos].lista = agregarAlFinal(adl[pos].lista, crearNodo(paciente));
    return validos;
}

stPaciente getPaciente(stRegistroMedico r) {
    stPaciente p;
    strcpy(p.apellidoPaciente, r.apellidoPaciente);
    strcpy(p.diagnostico, r.diagnostico);
    strcpy(p.fechaAtencion, r.fechaAtencion);
    p.idPaciente = r.idPaciente;
    p.idRegistro = r.idRegistro;
    strcpy(p.nombreDoctor, r.nombreDoctor);
    strcpy(p.nombrePaciente, r.nombrePaciente);

    return p;
}

stEspecialidadMedica getEspecialidadMedica(stRegistroMedico r) {
    stEspecialidadMedica e;
    strcpy(e.especialidadMedica, r.especialidadMedica);
    e.idEspecialidad = r.idEspecialidad;
    
    return e;
}

int altaADL(celda adl[], int dimension, char nombreArchivo[]) {
    int validos = 0;
    FILE* archivo = fopen(nombreArchivo, "rb");
    stRegistroMedico buffer;
    stEspecialidadMedica especialidad;
    stPaciente paciente;

    if(archivo) {
        while(validos < dimension && fread(&buffer, sizeof(stRegistroMedico), 1, archivo) > 0) {
            especialidad = getEspecialidadMedica(buffer);
            paciente = getPaciente(buffer);

            validos = alta(adl, validos, especialidad, paciente);
        }
        fclose(archivo);
    }

    return validos;
}

void muestraArregloCelda(celda c[], int validos) {
    for(int i=0; i<validos; i++) {
        muestraUnaCelda(c[i]);
    }
}

void muestraArchivo(char nombreArchivo[]) {
    FILE* archi = fopen(nombreArchivo, "rb");
    stRegistroMedico r;

    if(archi) {
        while(fread(&r, sizeof(stRegistroMedico), 1, archi) > 0) {
            mostrarUnRegistro(r);
        }

        fclose(archi);
    }
}

int buscaPacienteAtendido(celda adl[], char nombre[], char apellido[], int validos) {
    int flag = 0, idABuscar = 0;

    for(int i=0; i<validos; i++) {
        printf("\n%d- \t%s", adl[i].dato.idEspecialidad, adl[i].dato.especialidadMedica);
    }

    printf("\nIngrese id: ");
    fflush(stdin);
    scanf("%d", &idABuscar);

    nodo* buscado = NULL;
    buscado = buscarNodoPorNombreYApellido(adl[idABuscar].lista, nombre, apellido);
    if(buscado != NULL) {
        flag = 1;
    }

    return flag;
}

int contarPacientesAtendidosEspecialidad(celda adl[], int validos) {
    int contador = 0, idAContar = 0;

    for(int i=0; i<validos; i++) {
        printf("\n%d- \t%s", adl[i].dato.idEspecialidad, adl[i].dato.especialidadMedica);
    }

    printf("\nIngrese id de especialidad a contar los pacientes: ");
    fflush(stdin);
    scanf("%d", &idAContar);

    contador = contarLista(adl[idAContar].lista);
}

int buscarEspecialidadPorNombre(celda adl[], char nombreEspecialidad[], int validos) {
    int flag = 0;
    int i = 0;
    while(i<validos && flag == 0) {
        if(strcmp(adl[i].dato.especialidadMedica, nombreEspecialidad) == 0) {
            flag = adl[i].dato.idEspecialidad;
        }
        i++;
    }
    return flag;
}

void muestraArchivoPaciente(char nombreArchivo[]) {
    FILE* archi = fopen(nombreArchivo, "rb");
    stPaciente p;

    if(archi) {
        while(fread(&p, sizeof(stPaciente), 1, archi) > 0) {
            muestraUnPaciente(p);
        }

        fclose(archi);
    }
}

void especialidadToArchi(celda adl[], char nombreArchivo[], char nombreEspecialidad[], int validos) {
    int idABuscar = buscarEspecialidadPorNombre(adl, nombreEspecialidad, validos);
    FILE* archi = fopen(nombreArchivo, "wb");
    stPaciente buffer;

    if(archi) {
        nodo* seg = adl[idABuscar].lista;
        while(seg) {
            buffer.idPaciente = seg->dato.idPaciente;
            buffer.idRegistro = seg->dato.idRegistro;
            strcpy(buffer.apellidoPaciente, seg->dato.apellidoPaciente);
            strcpy(buffer.nombrePaciente, seg->dato.nombrePaciente);
            strcpy(buffer.diagnostico, seg->dato.diagnostico);
            strcpy(buffer.fechaAtencion, seg->dato.fechaAtencion);
            strcpy(buffer.nombreDoctor, seg->dato.nombreDoctor);

            fwrite(&buffer, sizeof(stPaciente), 1, archi);
            seg = seg->siguiente;
        }
        fclose(archi);
    }
}



int main()
{
    int validos = 0, dimension = 10, buscado = 0, totalPacientesEspecialidad;
    celda especialidades[dimension];
    char archivoNuevo[40] = {"nuevaEspecialidad.dat"};

    validos = altaADL(especialidades, dimension, arRegistro);
    muestraArregloCelda(especialidades, validos);

    buscado = buscaPacienteAtendido(especialidades, "Remilgo", "De Antonio", validos);
    printf("\nEncontrado: %d", buscado);

    totalPacientesEspecialidad = contarPacientesAtendidosEspecialidad(especialidades, validos);
    printf("\nTotal en esta especialidad: %d", totalPacientesEspecialidad);

    especialidadToArchi(especialidades, archivoNuevo, "Neumologia pediatrica", validos);
    muestraArchivoPaciente(archivoNuevo);



    //muestraArchivo(arRegistro);

    return 0;
}
