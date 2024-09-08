/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:22:09 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/08 20:36:43 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pipex.h"

void	ft_perror(char *str, int code)
{
	perror(str);
	exit(code);
}

void	ft_error(char *str, int code)
{
	ft_putstr_fd(str, 2);
	exit(code);
}
