/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:50:52 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:50:47 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*new_string;
	int		len;

	len = 0;
	while (src[len])
		len++;
	new_string = (char *)malloc(len + 1);
	if (new_string == NULL)
		return (NULL);
	new_string[len] = 0;
	while (len--)
		new_string[len] = src[len];
	return (new_string);
}
