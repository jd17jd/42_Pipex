/*
ESTRUCTURA DE WAITPID:
	pid_t waitpid(pid_t pid, int *status, int options);

OBJETIVO:
    Suspende la ejecucion del proceso llamante hasta que un hijo especificado por el argumento pid haya cambiado de estado.
    Por defecto, la funcion espera solo a hijos que hayan terminado.

RESULTADO:
    PID del proceso hijo que ha terminado o
    0 en caso de que no haya procesos hijos que coincidan con el criterio especiificado, en caso de exito
    -1 en caso de error

PARAMETROS:
    "pid" es el PID del proceso hijo que se espera.

    "status" es un puntero a un entero donde se almacenará el estado de salida del hijo.
    Es opcional; si no estás interesado en el estado de salida del proceso hijo, puedes pasar NULL.

    "options" son opciones adicionales para el comportamiento de la función. Algunas son:
    WNOHANG: Devuelve inmediatamente si no hay procesos hijos que hayan terminado.
    WUNTRACED: Devuelve también si un proceso hijo ha sido detenido y no ha sido continuado.
    WCONTINUED: Devuelve también si un proceso hijo ha sido continuado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Crear un proceso hijo
    if ((pid = fork()) == -1) {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Código del proceso hijo
        printf("Proceso hijo ejecutando...\n");
        sleep(3);  // Simulación de trabajo en el proceso hijo
        printf("Proceso hijo terminando.\n");
        exit(EXIT_SUCCESS);
    }

    else {
        // Código del proceso padre
        printf("Proceso padre esperando a que el hijo termine...\n");

        // Utilizando waitpid para esperar al proceso hijo específico
        int status;
        pid_t terminated_pid = waitpid(pid, &status, 0);

        if (terminated_pid == -1) {
            perror("Error en waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) { //Si ha terminado normalmente
            printf("Proceso hijo con PID %d terminado con estado: %d\n", terminated_pid, WEXITSTATUS(status));
        }
        
        else {
            printf("Proceso hijo con PID %d terminado de manera anormal\n", terminated_pid);
        }
    }

    return (0);
}
