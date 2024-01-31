/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:22:22 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:26:23 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/** 
 * Duplicates a string. Allocates enough memory to do the copy and returns
 * a pointer to a string where the copy was done
 * @param s1 string to copy
 * @return Pointer to the new allocated string
*/
char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1) + 1);
	return (dest);
}
