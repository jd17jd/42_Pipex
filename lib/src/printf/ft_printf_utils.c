/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:56:39 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/07 20:09:14 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_put_base(unsigned long n, const char *base)
{
	int				i;
	int				j;
	unsigned long	aux;

	i = 0;
	aux = ft_strlen(base);
	if (n >= aux)
		i += ft_put_base(n / aux, base);
	j = ft_putchar(base[n % aux]);
	if (j == -1)
		return (-1);
	i += j;
	return (i);
}

int	ft_putptr(unsigned long ptr, const char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_putchar('0') == -1)
		return (-1);
	if (ft_putchar('x') == -1)
		return (-1);
	j = ft_put_base(ptr, base);
	if (j == -1)
		return (-1);
	i = j + 2;
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
	}
	i += ft_putchar(n % 10 + '0');
	return (i);
}
