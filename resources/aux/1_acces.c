/*
ESTRUCTURA DE ACCESS:
	int access(const char *pathname, int mode);

OBJETIVO:
	Comprueba si el programa puede acceder en el modo indicado al pathname file

RESULTADO:
	0 en caso de éxito, -1 en caso de error

PARAMETROS:
	"pathname" nombre del archivo para acceder
	
	"mode" especifica las comprobaciones de accesibilidad que se realizrán. Puede ser los valores:
		F_OK = comprueba la existencia del fichero
	o
		R_OK = Comprueba existencia del fichero y permiso de lectura
		W_OK = Comprueba existencia del fichero y permiso de escritura
		X_OK = Comprueba existencia del fichero y permiso de ejecucion
*/ 

#include <unistd.h>
#include <stdio.h>

int main()
{
	if (access("example.txt", F_OK) != -1)
		printf("example.txt exists\n");

    if (access("readfile", R_OK) == 0)
        printf("readfile is accessible in reading mode\n");

    if (access("writefile", W_OK) == 0)
        printf("writefile is accessible in writing mode\n");

    if (access("executefile", X_OK) == 0)
        printf("executefile is accessible in execution mode\n");

    if (access("rwfile", R_OK|W_OK) == 0)
        printf("rwfile is accessible in writing and reading mode\n");

	return (0);
}