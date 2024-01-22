/*
ESTRUCTURA DE PIPE:
	int pipe(int pipefd[2]);

OBJETIVO:
	pipe() crea una tuberia, un canal unidireccional de informacion que puede ser usado para comunicacion de interprocesos.
	0 en caso de exito, -1 en caso de error

PARAMETROS:
	"pipefd[2]" es usado para devolver dos fd refiriendose a cada extremo de la tubería.
		pipefd[0] se refiere al extremo de la lectura de la tuberia
		pipefd[1] se refiere al extremo de la escritura de la tuberia

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
	int fd[2];
	pid_t pid;
	char buffer[13];
 
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		close(fd[0]); // close the read end of the pipe
		write(fd[1], "Hello parent!", 13);
		close(fd[1]); // close the write end of the pipe
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // close the write end of the pipe
		read(fd[0], buffer, 13);
		close(fd[0]); // close the read end of the pipe
		printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
}