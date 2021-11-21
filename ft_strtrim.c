/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:58:12 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 18:44:37 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (c == s1[i++])
			return (1);
	}
	return (0);
}

static int	get_trimed_string_length(char const *s1, char const *set)
{
	int	sz;
	int	c;
	int	i;
	int	tmp;

	sz = 0;
	c = 0;
	i = 0;
	while (s1[sz])
		sz++;
	tmp = sz;
	while (s1[i] && is_in_set(s1[i++], set))
		c++;
	while (sz-- > i && is_in_set(s1[sz], set))
		c++;
	return (tmp - c);
}

static void	ft_strcpy(char *s, char const *s1, int l)
{
	int	i;

	i = 0;
	while (l--)
	{
		s[i] = s1[i];
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		len;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = get_trimed_string_length(s1, set);
	p = (char *) malloc(len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = 0;
	i = 0;
	while (is_in_set(s1[i], set))
		i++;
	ft_strcpy(p, &s1[i], len);
	return (p);
}
