/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:32:39 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/28 01:49:02 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Adds a new node at the beginning of a linked list
 * @param lst Pointer to a t_list pointer,
 * pointing at the beginning of the list
 * @param new Pointer to the new node to be added
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	lst[0] = new;
}
