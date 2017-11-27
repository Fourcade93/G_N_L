/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:31:32 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/05 19:25:12 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*crate_ncontent(t_list *new, void const *c, size_t c_size)
{
	void	*nc;

	nc = ft_memalloc(c_size);
	if (!nc)
	{
		free(new);
		return (NULL);
	}
	nc = ft_memcpy(nc, c, c_size);
	return (nc);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	size_t	nsize;
	void	*ncontent;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ncontent = crate_ncontent(new, content, content_size);
		if (!ncontent)
			return (NULL);
		nsize = content_size;
		new->content = ncontent;
		new->content_size = nsize;
	}
	new->next = NULL;
	return (new);
}
