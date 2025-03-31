/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:43:53 by soviet            #+#    #+#             */
/*   Updated: 2025/03/03 14:00:28 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int x)
{
	return (((1 - (2 * (x < 0))) * x));
}
