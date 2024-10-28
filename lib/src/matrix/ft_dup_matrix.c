/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:55:25 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/07 19:50:20 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* Duplicates a char** object */
char	**ft_dup_matrix(char **matrix)
{
	char	**res;
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	res = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		res[i] = ft_strdup(matrix[i]);
		i++;
	}
	return (res);
}
