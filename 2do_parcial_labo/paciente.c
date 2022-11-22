#include<stdio.h>
#include<stdlib.h>

#include"paciente.h"

void muestraUnPaciente(stPaciente paciente) {
    printf("\nID del Paciente: %d", paciente.idPaciente);
    printf("\nID del registro: %d", paciente.idRegistro);
    printf("\nApellido Paciente: %s", paciente.apellidoPaciente);
    printf("\nNombre Paciente: %s", paciente.nombrePaciente);
    printf("\nDiagnostico: %s", paciente.diagnostico);
    printf("\nFecha de Atencion: %s", paciente.fechaAtencion);
    printf("\nDoctor a cargo: %s", paciente.nombreDoctor);
    printf("\n_________________________________________________________________");
}