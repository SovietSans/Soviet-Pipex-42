/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_chained_list.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:58:17 by soviet            #+#    #+#             */
/*   Updated: 2025/03/03 14:01:37 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_CHAINED_LIST_H
# define DOUBLE_CHAINED_LIST_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*previous;
	struct s_dlist	*next;
}				t_dlist;

t_dlist			*ft_lstmap(t_dlist *lst, void *(*f)(void *),
					void (*del)(void *));
t_dlist			*ft_lstnew(void *content);
t_dlist			*ft_lstlast(t_dlist *lst);
size_t			ft_lstsize(t_dlist *lst);
void			ft_lstadd_front(t_dlist **lst, t_dlist *new);
void			ft_lstadd_back(t_dlist **lst, t_dlist *new);
void			ft_lstdelone(t_dlist *lst, void (*del)(void*));
void			ft_lstclear(t_dlist **lst, void (*del)(void*));
void			ft_lstiter(t_dlist *lst, void (*f)(void *));

#endif
