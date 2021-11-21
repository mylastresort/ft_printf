/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:36:16 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:50:41 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_crash(char **p, int i)
{
	while (i--)
		free(p[i]);
	free(p);
	return (NULL);
}

static int	get_words_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		count++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static void	ft_strcpy(char *p, char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
}

static char	**push_strings(char const *s, char c, int n, char **p)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	count = 0;
	while (s[count] && s[count] == c)
		count++;
	while (n > i)
	{
		size = 0;
		while (s[size + count] && s[size + count] != c)
			size++;
		p[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (p[i] == NULL)
			return (malloc_crash(p, i));
		ft_strcpy(p[i], (char *)s + count, c);
		count += size;
		while (s[count] && s[count] != c)
			count++;
		while (s[count] && s[count] == c)
			count++;
		i++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		n;

	if (s == NULL)
		return (NULL);
	n = get_words_count(s, c);
	p = (char **)malloc(sizeof(char *) * (n + 1));
	if (p == NULL)
		return (NULL);
	p[n] = NULL;
	if (s[0] != 0)
		return (push_strings(s, c, n, p));
	return (p);
}
