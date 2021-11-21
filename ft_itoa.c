/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:12:24 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:48:37 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits_count(long long n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		l;

	n = (long long)n;
	l = get_digits_count(n);
	if (n < 0)
		l++;
	p = (char *)malloc(l + 1);
	if (p == NULL)
		return (NULL);
	if (n < 0)
		p[0] = '-';
	p[l] = 0;
	if (n == 0)
		p[0] = '0';
	while (l && n != 0)
	{
		if (n < 0)
			p[--l] = 48 - (n % 10);
		else
			p[--l] = 48 + (n % 10);
		n /= 10;
	}
	return (p);
}
