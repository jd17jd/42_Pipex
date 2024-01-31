/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:16:35 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:23:37 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Sends the number "n" to the given file descriptor
 * @param n Number to send
 * @param fd The file descriptor to send "n"
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (-2147483648 <= n && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			n %= 10;
		}
		ft_putchar_fd(n + 48, fd);
	}
}
