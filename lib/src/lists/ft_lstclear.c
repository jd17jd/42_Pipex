/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:56:45 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/28 02:00:18 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Deletes and frees the allocated memory by all the nodes of a linked list
 * and leaves the list empty
 * @param lst Pointer to a t_list pointer,
 * pointing at the beginning of the list
 * @param del Pointer to a function that takes the void pointer and frees
 * the allocated memory linked to that pointer
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	while (*lst)
	{
		aux = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = 0;
}
