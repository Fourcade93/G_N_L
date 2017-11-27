/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:42:56 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/17 18:45:33 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	if (alst != NULL && del != NULL)
		if ((*alst))
			while ((*alst))
			{
				buf = (*alst);
				(*alst) = (*alst)->next;
				del(buf->content, buf->content_size);
				free(buf);
				buf = NULL;
			}
}
