/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:24:18 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:25:56 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Finds the first occurrence of the character "c" in the first "n" ​​bytes
 * in a memory region "s". 
 * @param s Searched memory region
 * @param c Character to find
 * @param n Examinated bytes in the memory region
 * @return Pointer to byte located. NULL otherwise
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
			return ((void *)&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
