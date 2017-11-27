/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:54:39 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/04 15:05:09 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delete_new(t_list *new)
{
	t_list	*buf;

	while (new)
	{
		buf = new->next;
		free(new);
		new = buf;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ret;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	lst = lst->next;
	ret = new;
	while (lst)
	{
		new->next = f(lst);
		if (new->next == NULL)
		{
			delete_new(ret);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (ret);
}
