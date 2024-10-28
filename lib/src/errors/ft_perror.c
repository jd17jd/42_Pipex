/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:31:54 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/27 23:34:43 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Shows a system error message (from perror) followed by an exit code
 * @param str String with a custom message to prefix the system error
 * @param code Exit code
 */
void	ft_perror(char *str, int code)
{
	errno = EINVAL;  // Configura errno a un error válido
	perror(str);
	exit(code);
}
