/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:16:27 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/02/21 18:58:50 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sends the character "c" to the given file descriptor
 * @param c Character to send
 * @param fd The file descriptor to send "ch"
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
