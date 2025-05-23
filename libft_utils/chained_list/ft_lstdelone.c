/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:54:56 by soviet            #+#    #+#             */
/*   Updated: 2025/01/20 14:55:30 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./chained_list.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*to_free;

	if (!lst || !del)
		return ;
	to_free = lst;
	lst = lst->next;
	del(to_free->content);
	free(to_free);
}
