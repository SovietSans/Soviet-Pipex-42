/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:49:06 by soviet            #+#    #+#             */
/*   Updated: 2025/01/20 14:56:17 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./double_chained_list.h"

t_dlist	*ft_lstnew(void *content)
{
	t_dlist	*lst;

	lst = (t_dlist *)malloc(1 * sizeof(t_dlist));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->previous = NULL;
	return (lst);
}
