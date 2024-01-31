/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:17:32 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:27:37 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Removes characters in string "set" from beginning and end of string "s1"
 * until finding a character not belonging to "set".
 * Resulting string is returned with a new allocated string.
 * @param s1 String to be trimmed.
 * @param set Characters to remove from s1
 * @return Allocated trimmed string. NULL if allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	res = ft_substr(s1, start, end - start);
	return (res);
}
