/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:07:11 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:48:45 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*a;

	if (lst != NULL && del != NULL)
	{
		a = *lst;
		while (a != NULL)
		{
			tmp = a->next;
			del(a->content);
			free(a);
			a = tmp;
		}
	}
	*lst = NULL;
}
