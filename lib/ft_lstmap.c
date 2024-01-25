/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:58:48 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/09 01:31:44 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
