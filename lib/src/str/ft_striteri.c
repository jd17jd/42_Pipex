/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:16:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:26:26 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Applies f function to each character of string s.
 * Function f takes as parameters a pointer to the character that it evaluates
 * and its index. Function f can modify string s charactes directly.
 * @param s String to be used on f.
 * @param f Function that evaluates all characters of s.
 * Takes as parameters the pointer to the character to be evaluated 
 * and its index.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
