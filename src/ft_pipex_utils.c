/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:11:05 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/08 21:56:19 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pipex.h"

/**
 * Gets the path in the format: route value + / + cmd
 * @param cmd Command we're looking for
 * @param paths The differents paths coming through the PATH value
 * @return Success: The string with the result path. Failure: (null)
*/
char	*find_path(char *cmd, char *paths[])
{
	int		i;
	char	*res;
	char	*almost_path;
	char	*accessable;

	i = 0;
	res = 0;
	while (paths[i] != NULL)
	{
		almost_path = ft_strjoin(paths[i], "/");
		accessable = ft_strjoin(almost_path, cmd);
		free(almost_path);
		if (access(accessable, F_OK | X_OK) == 0)
			return (accessable);
		free(accessable);
		i++;
	}
	return (res);
}

/**
 * Frees the memory allocated of a double pointer
 * @param strings Pointer to pointer to free
*/
void	free_double_pointer(char *strings[])
{
	int	i;

	if (strings == NULL)
		return ;
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

/**
 * Gets the path from the given PATH-value part the command searched
 * @param cmd Command we're looking for
 * @param evp Environment variables
 * @return Success: The string with the result path. Failure: (null)
*/
char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	*res;
	char	**envp_divided;
	char	**envp_right;

	i = 0;
	if (envp == NULL || *envp == NULL)
		ft_error("There is no PATH defined\n", 6);
	if (cmd[0] == '/')
		return (ft_strdup(cmd));
	while (envp[i] != NULL && i != -1)
	{
		envp_divided = ft_split(envp[i], '=');
		i++;
		if (ft_strncmp(envp_divided[0], "PATH", 4) == 0)
		{
			envp_right = ft_split(envp_divided[1], ':');
			i = -1;
		}
		free_double_pointer(envp_divided);
	}
	res = find_path(cmd, envp_right);
	free_double_pointer(envp_right);
	return (res);
}

/**
 * Executes the string command given. In failure shows error
 * @param cmd The string command given
 * @param evp Environment variables
*/
void	execute_cmd(char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**cmd_arguments;

	cmd_arguments = ft_split(cmd, ' ');
	cmd_path = get_path(cmd_arguments[0], envp);
	if (!cmd_path)
	{
		ft_error("Command not found or no valid path\n", 7);
		free_double_pointer(cmd_arguments);
	}
	if (execve(cmd_path, cmd_arguments, envp) < 0)
	{
		ft_error("Command not found or no valid path\n", 7);
		free_double_pointer(cmd_arguments);
		free(cmd_path);
	}
	free_double_pointer(cmd_arguments);
	free(cmd_path);
}
