/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:09:40 by soviet            #+#    #+#             */
/*   Updated: 2025/01/20 14:55:28 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./chained_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_free;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		to_free = *lst;
		*lst = lst[0]->next;
		del(to_free->content);
		free(to_free);
	}
	*lst = NULL;
}
