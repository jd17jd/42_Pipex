/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:58:48 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/28 02:15:28 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Creates a new linked list applying a function f to each node
 * of a linked list given
 * @param lst Pointer to the first node of the linked
 * @param f Pointer to a function that takes the void pointer as an argument
 * and performs some operation with it
 * @param del Pointer to a void function that takes the void pointer as argument
 * and frees the allocated memory linked to that pointer
 * @return A new linked list containing the results of applying
 * the function to each element
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*elto;
	void	*content;

	res = NULL;
	while (lst)
	{
		content = f(lst->content);
		elto = ft_lstnew(content);
		if (!elto)
		{
			free(content);
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, elto);
		lst = lst -> next;
	}
	return (res);
}
