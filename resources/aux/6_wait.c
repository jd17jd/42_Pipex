/*
ESTRUCTURA DE WAIT:
	pid_t wait(int *status);

OBJETIVO:
	La llamada a la funcion suspende la ejecucion de los procesos llamantes (proceso padre) hasta que uno de sus hijos termina
	The wait() system call suspends execution of the calling process until one of its children terminates.

RESULTADO:
	PID del proceso hijo que ha terminado o -1 en caso de error.
	Si no hay procesos hijos, la llamada a wait() bloqueará la ejecucion del proceso padre hasta que haya al menos un proceso jijo que haya terminado

PARAMETRO:
	"status" es donde se almacenará el estado de salida del proceso hijo. Este parámetro es opcional; si no estás interesado en el estado de salida del proceso hijo, puedes pasar NULL.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("I am the child process.\n");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("I am the parent process.\n");
		wait(NULL);
		printf("Child process terminated after a 2s delay.\n");
	}
 
	return (EXIT_SUCCESS);
}