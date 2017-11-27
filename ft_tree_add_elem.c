/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_add_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:52:45 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/09 19:52:47 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_add_elem(t_tree **root, t_tree *new)
{
	if ((*root) == NULL)
		(*root) = new;
	else if (new->val <= (*root)->val)
		ft_tree_add_elem(&(*root)->left, new);
	else
		ft_tree_add_elem(&(*root)->right, new);
}
