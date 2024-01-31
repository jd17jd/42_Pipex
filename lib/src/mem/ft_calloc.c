/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:55:53 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:25:53 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
	void	*res;

	res = (void *)malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, (count * size));
	return (res);
}
