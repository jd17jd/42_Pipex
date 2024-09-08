/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:03:01 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/08 21:58:46 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pipex.h"

/**
 * Handles the input file,
 * redirects the standard input to the file and the standard output to the pipe.
 * Executes the 1st command and writes its output to the pipe.
 * 
*/
void	child_input_process(char *argv[], int *fd, char *envp[])
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY, 0644);
	if (fd_infile < 0)
		ft_error("No such file or directory\n", 4);
	close(fd[0]);
	dup2(fd_infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(argv[2], envp);
	close(fd_infile);
}

/**
 * Handles the output file, redirects the standard input to the pipe
 * and the standard output to the output file- Takes the output of the 1st
 * process from the pipe and executes it in the 2nd command,
 * writing it to the output file.
 * 
*/
void	child_output_process(char *argv[], int *fd, char *envp[])
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
		ft_error("Error occurred when trying to open or create the file\n", 5);
	close(fd[1]);
	dup2(fd_outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	execute_cmd(argv[3], envp);
	close(fd_outfile);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (argc != 5)
		ft_error("Incorrect number of parameters entered\n", 1);
	if (pipe(fd) < 0)
		ft_perror("Error creating pipe\n", 2);
	pid1 = fork();
	if (pid1 < 0)
		ft_perror("Error creating first process\n", 3);
	if (pid1 == 0)
		child_input_process(argv, fd, envp);
	pid2 = fork();
	if (pid2 < 0)
		ft_perror("Error creating second process\n", 3);
	if (pid2 == 0)
		child_output_process(argv, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (0);
}
