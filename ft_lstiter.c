/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:50:31 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/04 13:53:32 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(t_list *elem))
{
	t_list	*tmp;

	if (list != NULL && f != NULL)
	{
		tmp = list;
		if (tmp)
			while (tmp)
			{
				f(tmp);
				tmp = tmp->next;
			}
	}
}
