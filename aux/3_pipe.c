/*
ESTRUCTURA DE PIPE:
	int pipe(int pipefd[2]);

OBJETIVO:
	pipe() crea una tuberia, un canal unidireccional de informacion que puede ser usado para comunicacion de interprocesos.

RESULTADO:
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

	// Creamos una tuberia con los dos descriptores que hemos creado
	// y comprobamos si la puede crear correctamente
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	// Creamos una proceso hijo y cmoprobamos si se puede crear correctly
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) //Estamos en el proceso hijo
	{
		close(fd[0]); // Cierra el extremo de lectura de la tuberia
		write(fd[1], "Hello parent!", 13); //Lo escribe en el padre (fd[1])
		close(fd[1]); // Cierra el extremo de escritura de la tuberia
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // Cierra el extremo de escritura de la tuberia
		read(fd[0], buffer, 13);
		close(fd[0]); // Cierra el extremo de lectura de la tuberia
		printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
}