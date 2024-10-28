/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:29:33 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/07 18:32:15 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Shows error message when required followed by an specific exit code
 * @param str String with the error message
 * @param code Exit code
*/
void	ft_error(char *str, int code)
{
	ft_putstr_fd(str, 2);
	exit(code);
}
