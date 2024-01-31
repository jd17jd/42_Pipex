/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:27:42 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:25:58 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Compares "n" bytes in memory regions pointed to by "s1" and "s2"
 * @param s1 First memory region to be compared
 * @param s2 Second memory region to be compared
 * @param n Number of bytes to compare
 * @return Integer number: 0 if the two regions are identical.
 * Positive value (1) if the first different character is greater in "s1".
 * Negative value (-1) if the first different character is greater in "s2".
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
