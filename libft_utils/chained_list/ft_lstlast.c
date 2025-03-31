/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:31 by soviet            #+#    #+#             */
/*   Updated: 2025/01/20 14:55:34 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./chained_list.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	if (lst->next != NULL)
		return (ft_lstlast(lst->next));
	else
		return (lst);
}
