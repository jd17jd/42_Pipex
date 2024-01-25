/*
ESTRUCTURA DE UNLINK:
	int unlink(const char *pathname);

OBJETIVO:
	Elimina un enlace a un archivo existente. Eliminar un enlace a un archivo no significa necesariamente eliminar el archivo en sí.
	Si ese enlace era el ultimo de un fichero y ningun proceso tiene el fichero abierto,
	el fihero se borra y el espacio que estaba usando queda disponible para reusarlo
	Si el enlace era el ultimo, pero algun proceso aun lo tiene abierto,
	el fichero seguira existiendo hasta que el ultimo file descriptor referido a él sea cerrado

RESULTADO:
	0 en caso de éxito, -1 en caso de error

PARAMETRO:
	"pathname" ruta al archivo del cual se eliminará el enlace
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *filename = "mi_archivo.txt";

    // Crear un archivo
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error al crear el archivo");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    printf("Archivo creado: %s\n", filename);

    // Eliminar el enlace al archivo
    if (unlink(filename) == -1) {
        perror("Error al eliminar el enlace al archivo");
        exit(EXIT_FAILURE);
    }

    printf("Enlace al archivo eliminado: %s\n", filename);

    return (0);
}
