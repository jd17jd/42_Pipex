/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:03:01 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/25 23:58:58 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	child_process(char *argv[], int *fd, char *envp[])
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY, 0644);
	if (fd_infile == -1)
	{
		perror("No such file or directory\n");
		exit(4);
	}
	dup2(fd_infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute_cmd(argv[2], envp);
	close(fd_infile);
}

void	parent_process(char *argv[], int *fd, char *envp[])
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		perror("Error occurred when trying to open or create the file\n");
		exit (5);
	}
	wait(NULL);
	dup2(fd_outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute_cmd(argv[3], envp);
	close(fd_outfile);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		perror("Incorrect number of parameters entered\n");
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("Error creating pipe\n");
		return (2);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error creating process\n");
		return (3);
	}
	if (pid == 0)
		child_process(argv, fd, envp);
	parent_process(argv, fd, envp);
	return (0);
}
