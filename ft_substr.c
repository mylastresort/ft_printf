/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:30:13 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:55:02 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_len(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*alloc_str(char *str, size_t start, size_t size, size_t len)
{
	if (start > size - 1)
		str = (char *)malloc(1);
	else if (size - start >= len)
		str = (char *)malloc(len + 1);
	else
		str = (char *)malloc(size - start + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	str = NULL;
	if (s != NULL && start >= 0 && len >= 0)
	{
		size = str_len(s);
		str = alloc_str(str, start, size, len);
		if (str == NULL)
			return (NULL);
		i = 0;
		if (start > size - 1)
			len = 0;
		size = size - start;
		while (len-- && i < size)
			str[i++] = s[start++];
		str[i] = 0;
	}
	return (str);
}
