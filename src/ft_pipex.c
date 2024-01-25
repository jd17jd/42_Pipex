/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:03:01 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/25 22:43:41 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

//Control de errores falta
void	childProcess(char *argv[], int *fd, char *envp[])
{
    int fdInfile;

    fdInfile = open(argv[1], O_RDONLY, 0644);
    if (fdInfile == -1)
    {
        perror("No such file or directory\n");
        exit(4);
    }
    dup2(fdInfile, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    executeCmd(argv[2], envp);
    close(fdInfile);
    //unlinks?
}

//Control de errores falta
void    parentProcess(char *argv[], int *fd, char *envp[])
{
    int fdOutfile;

    fdOutfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fdOutfile == -1)
    {
        perror("Error occurred when trying to open or create the file\n");
        exit (5);
    }
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
    int fd[2];
	pid_t pid;

    if (argc != 5) { //OK
        perror("Incorrect number of parameters entered\n");
        return (1);
    }

    //check_access_files(argv);
        
    if (pipe(fd) == -1) { //OK
        perror("Error creating pipe\n");
        return (2);
    }

	pid = fork(); //OK
	if (pid == -1) {
		perror("Error creating process\n");
        return (3);
	}
    
	if (pid == 0)
        childProcess(argv, fd, envp);
    
    parentProcess(argv, fd, envp);
    return (0);
}
