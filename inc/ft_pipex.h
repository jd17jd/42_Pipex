/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:53 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/08 20:38:48 by jvivas-g         ###   ########.fr       */
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
# include "../lib/inc/libft.h"

/* FUNCIONES PRINCIPALES */
void	child_input_process(char *argv[], int *fd, char *envp[]);
void	child_output_process(char *argv[], int *fd, char *envp[]);

/* FUNCIONES AUXILIARES */
void	free_double_pointer(char *strings[]);
char	*find_path(char *cmd, char *paths[]);
char	*get_path(char *cmd, char *envp[]);
void	execute_cmd(char *cmd, char *envp[]);
void	ft_perror(char *str, int code);
void	ft_error(char *str, int code);

#endif