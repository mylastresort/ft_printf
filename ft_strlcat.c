/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:44:59 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:51:02 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	sz;
	size_t	len;

	sz = 0;
	while (src[sz])
		sz++;
	if (dstsize <= 0)
		return (sz);
	c = 0;
	while (dst[c])
		c++;
	if (dstsize <= c)
		return (sz + dstsize);
	len = c + sz;
	while (c < (dstsize - 1) && *src)
	{
		dst[c++] = *src;
		src++;
	}
	dst[c] = 0;
	return (len);
}
