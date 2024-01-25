/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/25 22:03:50 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/**
 * Checks if the given arguments are correct
 * @param fdInfile File descirptor of the input file
 * @param fdOutfile File descriptor of the output file
 * @return Success: 0. Failure: -1.
*/
int	ft_check_files(int fdInfile, int fdOutfile)
{
    if (fdInfile == -1)
	{
        perror("No such file or directory\n");
        return (1);
    }  
    if (fdOutfile == -1)
	{
        perror("Error occurred when trying to open or create the file\n");
        return (2);
    }
    if (fdInfile == -1 && fdOutfile == -1)
    {
        perror("Error occured when trying to open both files\n");
        return (3);
    }
    return (0);
}

//Control de errores falta
void	childProcess(char *argv[], int *fd, int fdInfile, char *envp[], int execute)
{
    if (execute == 0) {
	    dup2(fdInfile, STDIN_FILENO);
	    dup2(fd[1], STDOUT_FILENO);
	    close(fd[0]);
	    executeCmd(argv[2], envp);
        close(fdInfile);
	    //unlinks?
    }
    exit(0);
}

//Control de errores falta
void    parentProcess(char *argv[], int *fd, int fdOutfile, char *envp[])
{
	wait(NULL);
    dup2(fdOutfile, STDOUT_FILENO);
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    executeCmd(argv[3], envp);
    close(fdOutfile);
	//unlinks?
}

int main(int argc, char *argv[], char *envp[])
{
    int fdInfile, fdOutfile, fd[2], execute;
	pid_t pid;

    //Num de argumentos --OK
    if (argc != 5) {
        perror("Incorrect number of parameters entered\n");
        return (1);
    }
    
    //Comprobamos los ficheros
    execute = 0;
    fdInfile = open(argv[1], O_RDONLY, 0644);
    fdOutfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (ft_check_files(fdInfile, fdOutfile) == 1)
        execute = 1;
        
    if (pipe(fd) == -1) { //Crea la tuberia --OK
        perror("Error creating pipe\n");
        return (3);
    }

	pid = fork(); //Creamos un nuevo proceso --OK
	if (pid == -1) {
		perror("Error creating process\n");
        return (4);
	}
    
	if (pid == 0)
        childProcess(argv, fd, fdInfile, envp, execute);
    
    parentProcess(argv, fd, fdOutfile, envp);
    return (0);
}
