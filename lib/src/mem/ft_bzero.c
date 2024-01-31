/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:37:01 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:25:49 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Writes "n" zero bytes starting at "str".
 * If "n" is zero, the function does nothing. 
 * @param str String to be filled
 * @param n Number of bytes to zero
*/
void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}
