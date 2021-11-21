/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:35:52 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 16:14:35 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int						i;
	unsigned char			*p;

	p = (unsigned char *) s;
	c = (unsigned char)c;
	i = 0;
	while (n-- > 0)
	{
		if (p[i] == c)
			return (p + i);
		i++;
	}
	return (0);
}
