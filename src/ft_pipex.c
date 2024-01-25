/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/25 02:31:52 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/**
 * Comprueba si los argumentos son correctos
 * 
 * @return 0 en caso de que no haya ningun error, otro numero en caso contrario
*/
int ft_check_files(int fdInfile, int fdOutfile) {
    
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

char *find(char *cmd, char *paths[]) {
    int i;
    char *res;
    char *almostPath;
    char *accessable;

    i = 0;
    res = 0;
    while(paths[i] != NULL) {
        almostPath = ft_strjoin(paths[i], "/");
        accessable = ft_strjoin(almostPath, cmd);
        free(almostPath);
        if (access(accessable, F_OK | X_OK) == 0)
            return(accessable);
		free(accessable);
        i++;
    }
    return (res);
}

char    *getPath(char *cmd, char *envp[]) {
    int i;
    char *res;
    char **envp_divided;
    char **envp_right;

    i = 0;
    while (envp[i] != NULL && i != -1) {
        envp_divided = ft_split(envp[i], '=');
        i++;
        if (ft_strncmp(envp_divided[0], "PATH", 4) == 0) { 
            envp_right = ft_split(envp_divided[1], ':');
            i = -1;
        }
        //free_split(envp_divided);
    }
    res = find(cmd, envp_right);
    //free_split(envp_right);
    return (res);
}

void    execute(char *cmd[], char *envp[]) { //Funcion donde haga el execve()
    char *cmdPath; // Definir la ruta al programa a ejecutar
    char **cmdArguments; // Argumentos del programa (el último elemento debe ser NULL)

    cmdArguments = ft_split(cmd, ' ');
    cmdPath = getPath(cmdArguments[0], envp);
    if (execve(cmdPath, cmdArguments, envp) == -1) {
        perror("Error en execve");
    }
    //free_split(cmdArguments);
}

//Control de errores falta
void	child_process(char *argv[], int *fd, int fdInfile, char *envp[])
{
	dup2(fdInfile, STDIN_FILENO); //Redirigimos la entrada estandar al infile
	dup2(fd[1], STDOUT_FILENO); //Redirigimos la salida estandar a la entrada de la tuberia
	close(fd[0]); //Cerramos la salida de la tubería
	execute(argv[2], envp); //Ejecutamos el primer comando
    close(fdInfile);
}

//Control de errores falta
void    parent_process(char *argv[], int *fd, int fdOutfile, char *envp[])
{
    dup2(fdOutfile, STDOUT_FILENO); //Redirigimos la salida estandar al ourfile
    dup2(fd[0], STDIN_FILENO); //Redirigimos la entrada estandar a la salida de la tuberia
    close(fd[1]); //Cerramos la entrada de la tuberia
    execute(argv[3], envp); // Ejecutamos el primer comando
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
    fdInfile = open(argv[1], O_RDONLY, 0644);
    fdOutfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (ft_check_files(fdInfile, fdOutfile) == -1)
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
