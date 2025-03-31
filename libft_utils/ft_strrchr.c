/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:41:08 by soviet            #+#    #+#             */
/*   Updated: 2024/10/17 17:18:33 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*l_occ;
	char	*occ;

	i = 0;
	l_occ = 0;
	occ = (char *)s;
	if ((char)c == 0)
	{
		occ = (char *)&s[ft_strlen(s)];
		return (occ);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			l_occ = &occ[i];
		i++;
	}
	return (l_occ);
}
