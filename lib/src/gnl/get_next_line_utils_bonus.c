/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:14:11 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/30 19:14:29 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Writes "n" zero bytes starting at "str".
 * If "n" is zero, the function does nothing. 
 * @param str String to be filled
 * @param n Number of bytes to zero
*/
void	ft_bzero(void *str, size_t n)
{
	char	*res;
	size_t	i;

	res = (char *)str;
	i = 0;
	while (i < n)
	{
		res[i] = '\0';
		i++;
	}
}

/**
 * Contiguously allocates enough space for "count" objects that are "size"
 * bytes of memory each and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero. 
 * @param count Number of objects we want to allocate memory for.
 * @param size Bytes of each objects.
 * @return Pointer to alllocated memory. NULL if allocation fails.
*/
void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = (char *)malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

/**
 * Calculates length of string s
 * @param s string
 * @return number of bytes until character null is found
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * Allocates memory with malloc() and returns a new string formed by the
 * concatenation of "s1" and "s2".
 * @param s1 The first string.
 * @param s2 The string to added to "s1".
 * @return The new string. NULL if the memory allocation fails
*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	return (res);
}

/**
 * Locates first occurrence of "c" in string "s".
 * @param s Searched string.
 * @param c Character to search.
 * @return Pointer to byte located, or NULL if there is no occurrence.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
