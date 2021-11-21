/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:58 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:50:30 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printn(long long nb, int fd)
{
	char	c;

	if (nb / 10 != 0)
		printn(nb / 10, fd);
	c = 48 + (nb % 10);
	write(fd, &c, 1);
}

void	ft_putnbr(long long nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	printn(nb, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
