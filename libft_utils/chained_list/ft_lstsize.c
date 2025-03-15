/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:25:08 by ttremel           #+#    #+#             */
/*   Updated: 2025/01/20 14:55:45 by ttremel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./chained_list.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
