/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:57:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/28 02:06:44 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Apply the function f to every node of a linked list
 * @param lst Pointer to the first node of a linked list
 * @param f Pointer to a function that takes the void pointer as an argument
 * and performs some operation with it
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
