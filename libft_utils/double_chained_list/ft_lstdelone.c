/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:54:56 by soviet            #+#    #+#             */
/*   Updated: 2025/01/20 14:56:07 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./double_chained_list.h"

void	ft_lstdelone(t_dlist *lst, void (*del)(void*))
{
	t_dlist	*to_free;

	if (!lst || !del)
		return ;
	to_free = lst;
	lst = lst->next;
	lst->next->previous = NULL;
	del(to_free->content);
	free(to_free);
}
