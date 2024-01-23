/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/23 02:01:58 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/**
 * Comprueba si los argumentos son correctos
 * @param argumentos: ficheros a evaluar
 * @return 0 en caso de que no haya ningun error, otro numero en caso contrario
*/
int ft_check_files(char *argumentos[])
{
    if (access(argumentos[1], F_OK | R_OK) == -1
    && (access(argumentos[4], F_OK | W_OK) == -1)) {
        perror("Error. Ambos no existen o no tienen permisos necesarios\n");
        return (2);
    }
    if (access(argumentos[1], F_OK | R_OK) == -1) {
        perror("Error. file1 no existe o no tiene permiso de lectura\n");
        return (3);
    }
    if (access(argumentos[4], F_OK | W_OK) == -1) {
        perror("Error. file2 no existe o no tiene permiso de escritura\n");
        return (4);
    }

    return (0);
}

/**
 * 
*/
char **arguments_divided(char *argv[], int n)
{
    char **res;

    res = ft_split(argv[n], ' ');
    return (res);
}



void	process_child(char *argv[], int *fd, char *envp[])
{
	int		fd2;

	fd2 = open_file(argv[1], 0);
	dup2(fd2, 0); 
	dup2(fd[1], STDOUT_FILENO); //Duplica el primer fd al segundo, cerrando el segundo 
	close(fd[0]);
	exec(argv[2], envp);
}

int main(int argc, char *argv[], char *envp[])
{
	int fd[2];
	pid_t pid;

    //Num de argumentos
    if (argc != 5) {
        perror("Error. Numero introducido incorrecto de parámetros\n");
        return 1;
    }
	ft_check_files(argv); //Comprueba los ficheros

	if (pipe(fd) == -1) { //Crea la tuberia
        perror("Error al crear la tuberia");
        return (5);
    }

	pid = fork(); //Creamos un nuevo proceso
	if (pid == -1) {
		perror("Error al crear el proceso");
        return (6);
	}
	
	if (pid == 0) { //Child process
        process_child(arguments_divided(argv, 2), fd, envp);
    }
	
	process_parent(arguments_divided(argv, 3), fd, envp);
    return (0);
}
