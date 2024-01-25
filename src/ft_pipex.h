/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:53 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/25 14:07:08 by jvivas-g         ###   ########.fr       */
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
void	childProcess(char *argv[], int *fd, int fdInfile, char *envp[]);
void	parentProcess(char *argv[], int *fd, int fdOutfile, char *envp[]);

/* FUNCIONES AUXILIARES */
int		ft_check_files(int fdInfile, int fdOutfile);
void	freeDoublePointer(char *strings[]);
char	*findPath(char *cmd, char *paths[]);
char	*getPath(char *cmd, char *envp[]);
void	executeCmd(char *cmd, char *envp[]);

#endif