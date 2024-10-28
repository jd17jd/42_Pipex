/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:37:38 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/04 12:37:45 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	count_substrs(const char *s, char c)
{
	int	res;
	int	same_word;

	res = 0;
	same_word = 0;
	while (*s)
	{
		if (*s != c && same_word == 0)
		{
			same_word = 1;
			res++;
		}
		else if (*s == c)
			same_word = 0;
		s++;
	}
	return (res);
}

static char	*get_substr(char const *s, char c, int strs)
{
	char	*res;
	int		i;
	int		rows;
	size_t	len;
	int		start;

	i = 0;
	rows = 0;
	while (rows <= strs)
	{
		len = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != 0)
		{
			len++;
			i++;
		}
		if (rows == strs)
			res = ft_substr(s, (unsigned int)start, len);
		rows++;
	}
	return (res);
}

static void	*clear_leaks(char **res, int strs)
{
	int	i;

	i = 0;
	while (i < strs)
		free(res[i++]);
	free(res);
	return (NULL);
}

/**
 * Fills an array of strings with the result of dividing the string "s" using
 * the chararacter "c" as separator.
* @param s String to divide
* @param c Separator char
* @return Null terminated array of strings
*/
char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	res = (char **) malloc(sizeof(char *) * (count_substrs(s, c) + 1));
	if (!res)
		return (NULL);
	res[count_substrs(s, c)] = NULL;
	i = 0;
	while (i < count_substrs(s, c))
	{
		res[i] = get_substr(s, c, i);
		if (res[i] == NULL)
			return (clear_leaks(res, i));
		i++;
	}
	return (res);
}
