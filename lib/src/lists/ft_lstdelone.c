/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:55:59 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/31 13:38:20 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Deletes a node from the linked list and frees its allocated memory
 * @param lst Pointer to the node to be deleted
 * @param del Pointer to a void function that takes the void pointer as
 * argument and frees the allocated memory linked to that pointer
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst -> content);
		free(lst);
	}
}
