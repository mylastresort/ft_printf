/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:45:41 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 16:18:17 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	while (s[i])
		i++;
	if (c == 0)
		return ((char *)s + i);
	i--;
	while (i >= 0 && s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
