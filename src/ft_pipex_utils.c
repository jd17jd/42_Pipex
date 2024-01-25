/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:11:05 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/25 13:49:22 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/**
 * Gets the path in the format: route value + / + cmd
 * @param cmd Command we're looking for
 * @param paths The differents paths coming through the PATH value
 * @return Success: The string with the result path. Failure: (null)
*/
char	*findPath(char *cmd, char *paths[])
{
	int		i;
    char	*res;
    char	*almostPath;
    char	*accessable;

    i = 0;
    res = 0;
    while(paths[i] != NULL)
	{
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

/**
 * Frees the memory allocated of a double pointer
 * @param strings Pointer to pointer to free
*/
void	freeDoublePointer(char *strings[])
{
	int i;
	
	if (strings == NULL)
		return;
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

/**
 * Gets the path from the PATH value part given the command searched
 * @param cmd Command we're looking for
 * @param evp Environment variables
 * @return Success: The string with the result path. Failure: (null)
*/
char    *getPath(char *cmd, char *envp[])
{
    int		i;
    char	*res;
    char	**envp_divided;
    char	**envp_right;

    i = 0;
    while (envp[i] != NULL && i != -1)
	{
        envp_divided = ft_split(envp[i], '=');
        i++;
        if (ft_strncmp(envp_divided[0], "PATH", 4) == 0) { 
            envp_right = ft_split(envp_divided[1], ':');
            i = -1;
        }
        freeDoublePointer(envp_divided);
    }
    res = findPath(cmd, envp_right);
    freeDoublePointer(envp_right);
    return (res);
}

/**
 * Executes the string command given. In failure shows error
 * @param cmd The string command given
 * @param evp Environment variables
*/
void    executeCmd(char *cmd, char *envp[])
{
    char	*cmdPath;
    char	**cmdArguments;
	//char	**cmdWithNull;
	//Alocar memoria para uno más,
	//Añadir lo de cmdArgument
	//En el ultimo añadir NUll
	
    cmdArguments = ft_split(cmd, ' '); //Ultimo NULL
    cmdPath = getPath(cmdArguments[0], envp);
    if (execve(cmdPath, cmdArguments, envp) == -1) { //Check
        perror("Error en execve");
    }
    freeDoublePointer(cmdArguments);
	free(cmdPath);
}