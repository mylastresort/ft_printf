/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:36:38 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 18:37:35 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	if (dst == 0 && src == 0)
		return (0);
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (dst < src)
	{
		i = -1;
		while (++i < len)
			p1[i] = p2[i];
	}
	else
	{
		if (len > 0)
		{
			while (len--)
				p1[len] = p2[len];
		}
	}
	return (dst);
}
