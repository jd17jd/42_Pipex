/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/11/30 23:28:27 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

// ft_init_pipex()

/* <infile ls -l | wc -l >outfile */
/* infile "ls -l" "wc -l" outfile */

/* <infile grep a1 | wc -w >outfile */
/* infile "grep a1" "wc -w" outfile */

/**
 * 1. Comprobacion de argumentos de programa
 * 2. Comprobacion de correcto funcionamiento de comandos
 * X. Creacion del proceso hijo
 * X. Creacion del proceso padre
*/


/**
 * Checkear si los argumentos son correctos
 * @param argc: Numero de argumentos del programa
 * @param argumentos: Los argumentos en si
 * @return 0 en caso de que no haya ningun error, otro numero en caso contrario
*/
int ft_check_files(char *argumentos[])
{ //Ficheros de lectura y escritura

    if (access(argumentos[1], F_OK | R_OK) == -1
    && (access(argumentos[4], F_OK | W_OK) == -1)) {
        perror("Error. Ambos no existen o no tienen permisos necesarios\n");
        return (2);
    }
    
    if (access(argumentos[1], F_OK | R_OK) == -1) {
        perror("Error. El primer fichero no existe o no tiene accesos de lectura\n");
        return (3);
    }
    if (access(argumentos[4], F_OK | W_OK) == -1) {
        perror("Error. El segundo fichero no existe o no tiene accesos de escritura\n");
        return (4);
    }

    return (0);
}

// int execve(const char *path, char *const argv[], char *const envp[]);

int ft_check_commands (char *argumentos[])
{ //Comandos correctos para ejecutar

    char **segundo_arg;
	char **tercer_arg;

	segundo_arg = ft_split(argumentos[2], ' ');
	tercer_arg = ft_split(argumentos[3], ' ');

	//execve();
	return (0);
}

void	process_child(char *argv[], int *fd, char *envp[])
{
	int		fd2;

	fd2 = open_file(argv[1], 0);
	dup2(fd2, 0);
	dup2(fd[1], 1);
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

	ft_check_files(argv);
	ft_check_commands(argv);

	if (pipe(fd) == -1) {
        perror("Error al crear la tuberia");
        return (5);
    }

	pid = fork();
	if (pid == -1) {
		perror("Error al crear el proceso");
        return (6);
	}
	
	if (pid == 0)
		process_child();
	
	process_parent();
    return (0);
}
