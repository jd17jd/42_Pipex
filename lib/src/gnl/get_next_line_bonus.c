/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:06:55 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 04:57:14 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @param str Character string
 * @return A line until a newline char
*/
char	*ft_get_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = (char *)ft_calloc((i + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = str[i];
	return (result);
}

/**
 * @param fd Descriptor where to start to read from
 * @param stash Variable estatica para concatenar con o ue hagamos
 * @return String with the concatenated strings
*/
char	*ft_append(int fd, char *stash)
{
	char	aux[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*aux2;

	read_bytes = 1;
	ft_bzero(aux, BUFFER_SIZE + 1);
	if (!stash)
		stash = ft_strjoin("", "");
	while (!ft_strchr(aux, '\n') && read_bytes)
	{
		read_bytes = read(fd, aux, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			ft_bzero(stash, 1);
			break ;
		}
		aux[read_bytes] = '\0';
		aux2 = stash;
		stash = ft_strjoin(stash, aux);
		free(aux2);
	}
	return (stash);
}

/**
 * Aux for lines of ft_new_start
*/
void	aux_strcat(int i, int j, char *stash, char *result)
{
	while (stash[i + j])
	{
		result[j] = stash[i + j];
		j++;
	}
}

/**
 * @param stash Static variable that will get modified by 
 * moving their pointer
 * @return String with the new vector after the newline char
*/
char	*ft_new_start(char *stash)
{
	char	*result;
	char	*aux;
	int		i;
	int		j;

	i = 0;
	aux = stash;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	if (stash[i] == '\n')
		i++;
	result = (char *)ft_calloc(1 + ft_strlen(stash) - i, sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	aux_strcat(i, j, stash, result);
	free(aux);
	return (result);
}

/**
 * Returns a full line ending in a ('/n') read by the file descriptor.
 * @param fd file descriptor
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_append(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_new_start(stash[fd]);
	return (line);
}
