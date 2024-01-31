/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:25:39 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/28 02:19:10 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Creates a new node for a linked list and assign a given content to that node
 * @param content Pointer to the content that will be assigned.
 * @return Pointer to aa new linked list starting by this node
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (0);
	list -> content = content;
	list -> next = NULL;
	return (list);
}
