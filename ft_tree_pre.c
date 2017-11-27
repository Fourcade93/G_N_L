/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_pre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:05:07 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/09 20:05:09 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_pre(t_tree *root, void (*f)(int))
{
	t_tree	*tmp;

	tmp = root;
	if (tmp->val)
		f(tmp->val);
	if (tmp->left)
		ft_tree_pre(tmp->left, f);
	if (tmp->right)
		ft_tree_pre(tmp->right, f);
}
