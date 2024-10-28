/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:20 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/08 22:22:10 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putchar(const char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_format(va_list args, char car)
{
	if (car == '%')
		return (ft_putchar('%'));
	else if (car == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (car == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (car == 'p')
		return (ft_putptr(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (car == 'd' || car == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (car == 'u')
		return (ft_put_base(va_arg(args, unsigned int), "0123456789"));
	else if (car == 'x')
		return (ft_put_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (car == 'X')
		return (ft_put_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else
		return (ft_putchar(car));
	return (0);
}

/**
 * @return Number of characters printed (excluding the last '\0' of strings)
 * @param str Formatos solicitados 
*/
int	ft_printf(char const *str, ...)
{
	int		res;
	int		i;
	va_list	args;

	res = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_format(args, str[i + 1]);
			i++;
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (res);
}
