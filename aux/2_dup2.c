/*
ESTRUCTURA DE DUP2:
	int dup2(int oldfd, int newfd);

OBJETIVO:
	La función devuelve un nuevo descriptor de archivo (newfd) que está asociado con el mismo archivo que oldfd.

RESULTADO:
	newfd en caso de éxito, -1 en caso de error.
	
	A tener en cuenta:
		Si oldfd no es un fd valido, la llamada falla y newfd no está cerrado
		Si oldfd es un fd valido y newfd tine el mismo valor que oldfd, dup2() no hace nada y devuelve newfd

PARAMETROS:
	"oldfd" descriptor de archivo existente que se duplicará.

	"newfd" descriptor de archivo al que se copiará oldfd. Si newfd ya está abierto, se cerrará antes de duplicar el descriptor.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
	int fd;
 
	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("This is printed in example.txt!\n");
 
	return (0);
}

