/*
ESTRUCTURA DE FORK:
	pid_t fork(void);

OBJETIVO:
	Crea un nuevo proceso duplicando el proceso llamante. El nuevo proceso, lo llamaremos proceso hijo, es una copia exacta del proceso llamante, excepto por algunos puntos
	
RESULTADO:
	En el proceso padre, fork() devuelve el PID (Identificador de proceso) del proceso hijo
	En el proceso hijo, fork() devuelve 0 para indicar que está en el nuevo proceso

PARAMETROS:
	No tiene
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
 
	if (pid == 0)
		printf("This is the child process. (pid: %d)\n", getpid());
	else
		printf("This is the parent process. (pid: %d)\n", getpid());
 
	return (0);
}