/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:31 by ttremel           #+#    #+#             */
/*   Updated: 2025/03/03 14:02:20 by ttremel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./double_chained_list.h"

t_dlist	*ft_lstlast(t_dlist *lst)
{
	if (lst == NULL)
		return (lst);
	if (lst->next != NULL)
		return (ft_lstlast(lst->next));
	else
		return (lst);
}
