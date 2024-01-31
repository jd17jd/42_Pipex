/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:17:17 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:26:42 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Each character of the function "s" uses the function "f" using
 * as parameters the index of each character in "s" and the character itself.
 * @param s String to iterate
 * @param f Function to apply on each character
 * @return The result of the string after the use of "f" oneach character.
 * NULL if the memory allocation fails
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}
