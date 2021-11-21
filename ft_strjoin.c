/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 07:10:01 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:56:04 by stamim           ###   ########.fr       */
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

static void	ft_strcpy(int start, char *dest, char const *src)
{
	int	i;

	i = 0;
	while (src[i])
		dest[start++] = src[i++];
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = str_len(s1) + str_len(s2);
	str = (char *) malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	ft_strcpy(0, str, s1);
	ft_strcpy(str_len(s1), str, s2);
	return (str);
}
