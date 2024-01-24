/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/24 01:52:16 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"


int ft_check_open(char *arguments[], int n) {
    int fRes;

    if (n == 1)
        fRes = open(arguments[n], O_RDONLY);
    
    if (n == 4)
        fRes = open(arguments[n], O_CREAT | O_RDWR | O_TRUNC, 0644);

    return (fRes);
}

/**
 * Comprueba si los argumentos son correctos
 * @param argumentos: ficheros a evaluar
 * @return 0 en caso de que no haya ningun error, otro numero en caso contrario
*/
int ft_check_files(char *arguments[], int fdInfile, int fdOutfile) {
    
    fdInfile = ft_check_open(arguments, 1);
    fdOutfile = ft_check_open(arguments, 4);
    
    if (fdInfile == -1) {
        perror("Error. file1 no existe o no tiene permiso de lectura\n");
        return (-1);
    }
        
    if (fdOutfile == -1) {
        perror("Se produjo un error al intentar abrir o crear el archivo");
        return (-1);
    }
    
    return (0);
}

/* int ft_check_files(char *argumentos[])
{
    // Si el primero no existe --> Error
    if (access(argumentos[1], F_OK | R_OK) == -1) {
        perror("Error. file1 no existe o no tiene permiso de lectura\n");
        return (3);
    }
    // Si el segundo no existe --> Lo crea
    if (access(argumentos[4], F_OK | W_OK) == -1) {
        perror("Error. file2 no existe o no tiene permiso de escritura\n");
        return (4);
    }

    return (0);
} */

/**
 * 
*/
char **arguments_divided(char *argv[], int n)
{
    char **res;

    res = ft_split(argv[n], ' ');
    return (res);
}

void    funcion() { //Funcion donde haga el execve()
    
}

//Control de errores falta
void	child_process(char *argv[], int *fd, int fdInfile, char *envp[])
{
	dup2(fdInfile, STDIN_FILENO); //Redirigimos la entrada estandar al infile
	dup2(fd[1], STDOUT_FILENO); //Redirigimos la salida estandar a la entrada de la tuberia
	close(fd[0]); //Cerramos la salida de la tubería
	funcion(argv[2], envp); //Ejecutamos el primer comando
    close(fdInfile);
}

//Control de errores falta
void    parent_process(char *argv[], int *fd, int fdOutfile, char *envp[])
{
    dup2(fdOutfile, STDOUT_FILENO); //Redirigimos la salida estandar al ourfile
    dup2(fd[0], STDIN_FILENO); //Redirigimos la entrada estandar a la salida de la tuberia
    close(fd[1]); //Cerramos la entrada de la tuberia
    funcion(argv[3], envp); // Ejecutamos el primer comando
    close(fdOutfile);
}

int main(int argc, char *argv[], char *envp[])
{
    int fdInfile, fdOutfile, fd[2];
	pid_t pid;

    //Num de argumentos
    if (argc != 5) {
        perror("Error. Numero introducido incorrecto de parámetros\n");
        return (1);
    }
    
    //Comprobamos los ficheros
    if (ft_check_files(argv, fdInfile, fdOutfile) == -1)
        return (2);
        
    if (pipe(fd) == -1) { //Crea la tuberia
        perror("Error al crear la tuberia");
        return (3);
    }

	pid = fork(); //Creamos un nuevo proceso
	if (pid == -1) {
		perror("Error al crear el proceso");
        return (4);
	}
	
	if (pid == 0) { //Child process
        child_process(arguments_divided(argv, 2), fd, fdInfile, envp);
    }
    
    wait(NULL);
	parent_process(arguments_divided(argv, 3), fd, fdOutfile, envp);
    return (0);
}
