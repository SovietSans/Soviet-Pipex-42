/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:58:55 by soviet            #+#    #+#             */
/*   Updated: 2025/01/20 14:56:15 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./double_chained_list.h"

t_dlist	*ft_lstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*duplst;
	t_dlist	*dup;
	char	*str;

	dup = NULL;
	duplst = NULL;
	if (!lst || !f || !del)
		return (duplst);
	while (lst != NULL)
	{
		str = (char *)f(lst->content);
		dup = ft_lstnew(str);
		if (!dup)
		{
			ft_lstclear(&duplst, del);
			del(str);
			return (NULL);
		}
		ft_lstadd_back(&duplst, dup);
		lst = lst->next;
	}
	return (duplst);
}
