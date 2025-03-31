/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:36:47 by soviet            #+#    #+#             */
/*   Updated: 2025/01/06 11:41:59 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *dest, size_t n)
{
	char		*dup;
	char		*tmp;
	size_t		i;

	if (!dest)
		return (NULL);
	i = 0;
	tmp = (char *)dest;
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (0);
	while (i < n)
	{
		dup[i] = tmp[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
