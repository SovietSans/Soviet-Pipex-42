/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:10:28 by soviet            #+#    #+#             */
/*   Updated: 2025/01/20 17:29:02 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./double_chained_list.h"
#include <stdio.h>

void	ft_lstadd_back(t_dlist **lst, t_dlist *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (lst[0] == NULL)
		ft_lstadd_front(lst, new);
	else if (lst[0]->next != NULL)
		ft_lstadd_back(&lst[0]->next, new);
	else
	{
		new->previous = lst[0];
		lst[0]->next = new;
	}
}
