/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:53:30 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 17:20:40 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	cursor;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] && len-- > 0)
	{
		cursor = 0;
		while (haystack[i] && haystack[i] == needle[cursor])
		{
			if (needle[++cursor] == 0)
				return ((char *)haystack + i - cursor + 1);
			i++;
		}
		len--;
		i -= cursor - 1;
	}
	return (0);
}
