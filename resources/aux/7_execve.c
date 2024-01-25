/*
ESTRUCTURA DE EXECVE:
	int execve(const char *filename, char *const argv[], char *const envp[]);

OBJETIVO:
	Ejecuta un programa en un nuevo proceso. Reemplaza la imagen del proceso actual con la imagen del programa especificado,
	lo que significa que el código, datos y estado del proceso actual se descartan y se sustituyen por el código, datos y estado del nuevo programa.

	execve() no crea un nuevo proceso como fork(). En cambio, reemplaza la imagen del proceso actual con la imagen del programa especificado.

RESULTADO:
	-1 en caso de error, y si tiene éxito, no devuelve nada porque el proceso actual se reemplaza por el nuevo programa.
	Si la llamada a execve() tiene éxito, el código subsiguiente en el programa no se ejecutará.

PARAMETROS:
	"filename" ruta de programa que se va a ejecutar
	"argv" array de punteros a cadenas que representan los argumentos del programa. El ultimo elemento debe ser NULL
	"envp" array de punteros a cadenas que representan las variables de entorno del programa. Puedes pasar NULL si no deseas cambiar el entorno.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Definir la ruta al programa a ejecutar
    const char *programPath = "/usr/bin/grep";

    // Argumentos del programa (el último elemento debe ser NULL)
    char *const arguments[] = {"/usr/bin/grep", "ejemplo", NULL};

    // Variables de entorno (pueden ser NULL)
    char *const environment[] = {NULL};

    // Intentar ejecutar el programa usando execve
    if (execve(programPath, arguments, environment) == -1) {
        perror("Error en execve");
        exit(EXIT_FAILURE);
    }

    // Este código no se ejecutará si execve tiene éxito
    printf("Este mensaje no se imprimirá\n");

    return 0;
}
