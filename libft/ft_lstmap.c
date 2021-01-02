/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:28:09 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 14:40:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_elem;

	if (!(new_elem = ft_lstnew((*f)(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (0);
	}
	new_list = new_elem;
	lst = lst->next;
	while (lst)
	{
		if (!(new_elem = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
