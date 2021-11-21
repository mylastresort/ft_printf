/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:18:13 by stamim            #+#    #+#             */
/*   Updated: 2021/11/21 15:48:59 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*malloc_crash(t_list *head, t_list *last, void (*del)(void *))
{
	t_list	*tmp;

	while (head != last)
	{
		tmp = head->next;
		if (del != NULL)
			del(head->content);
		free(head);
		head = tmp;
	}
	del(last->content);
	free(last);
	return (NULL);
}

static t_list	*generate_list(
	t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ins;
	t_list	*next_ins;

	ins = (t_list *)malloc(sizeof(t_list));
	if (ins == NULL)
		return (NULL);
	head = ins;
	while (lst != NULL)
	{
		ins->content = f(lst->content);
		if (lst->next == NULL)
		{
			ins->next = NULL;
			return (head);
		}
		next_ins = (t_list *)malloc(sizeof(t_list));
		if (next_ins == NULL)
			return (malloc_crash(head, ins, del));
		ins->next = next_ins;
		lst = lst->next;
		ins = next_ins;
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (lst != NULL && f != NULL)
		return (generate_list(lst, f, del));
	return (NULL);
}
