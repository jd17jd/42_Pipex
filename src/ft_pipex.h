/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:53 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/25 23:49:40 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <stdlib.h>
# include <sys/fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../lib/libft.h"

/* FUNCIONES PRINCIPALES */
void	child_process(char *argv[], int *fd, char *envp[]);
void	parent_process(char *argv[], int *fd, char *envp[]);

/* FUNCIONES AUXILIARES */
int		ft_check_files(int fd_infile, int fd_outfile);
void	free_double_pointer(char *strings[]);
char	*find_path(char *cmd, char *paths[]);
char	*get_path(char *cmd, char *envp[]);
void	execute_cmd(char *cmd, char *envp[]);

#endif