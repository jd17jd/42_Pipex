/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/21 23:52:42 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/* ./pipex file1 cmd1 cmd2 file2 */
/* < file1 cmd1 | cmd2 > file2 */
/* < infile grep ejemplo | wc -w > outfile */


/**
 * Comprueba si los argumentos son correctos
 * @param argumentos: 
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

// int execve(const char *path, char *const argv[], char *const envp[]);

/**
 * 
*/
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

	ft_check_files(argv); //Comprueba los ficheros
	ft_check_commands(argv); //Parsea los comandos

	if (pipe(fd) == -1) {
        perror("Error al crear la tuberia");
        return (5);
    }

	pid = fork();
	if (pid == -1) {
		perror("Error al crear el proceso");
        return (6);
	}
	
	// if (pid == 0)
		// process_child();
	
	process_parent();
    return (0);
}
