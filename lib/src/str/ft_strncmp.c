/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:56:01 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:27:26 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Compares "n" bytes in memory regions pointed to by "s1" and "s2"
 * Compares for "n" bytes long.
 * @param s1 String 1.
 * @param s2 String 2.
 * @param n Number of bytes to compare.
 * @return Integer number: 0 if the two regions are identical.
 * Positive value (1) if the first different character is greater in "s1".
 * Negative value (-1) if the first different character is greater in "s2".
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i + 1 < n)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
