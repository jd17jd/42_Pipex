/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:02:06 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:27:53 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	aux_len(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*aux_str(int n, int len)
{
	char	*res;

	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

/**
 * Converts the integer n to a string. The result is returned in an
 * allocated string. Negative numbers are managed.
 * @param n Number to translate to string.
 * @return Pointer to the allocated string with the result.
 * NULL if allocation fails
 */
char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*res;

	sign = 1;
	len = aux_len(n);
	if (n < 0)
	{
		sign = -1;
		len++;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n *= sign;
	res = aux_str(n, len);
	if (!res)
		return (NULL);
	if (sign == -1)
		res[0] = '-';
	return (res);
}
