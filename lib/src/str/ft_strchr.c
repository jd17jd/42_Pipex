/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:31:32 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:26:21 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Locates first occurrence of "c" in string "s".
 * Uses the ft_memchr function
 * @param s Searched string.
 * @param c Character to search.
 * @return Pointer to byte located, or NULL if there is no occurrence.
 */
char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
