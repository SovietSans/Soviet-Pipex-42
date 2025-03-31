/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ubase_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:01:30 by soviet            #+#    #+#             */
/*   Updated: 2024/11/01 13:18:36 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ubase_count(unsigned int n, int base)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size++;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}
