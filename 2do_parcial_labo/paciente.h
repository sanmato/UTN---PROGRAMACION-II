#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct stPaciente {
    int idRegistro;
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char nombreDoctor[30];
}stPaciente;

void muestraUnPaciente(stPaciente paciente);

#endif //PACIENTE_H