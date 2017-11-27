/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:10:28 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/09 20:10:30 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_in(t_tree *root, void (*f)(int))
{
	t_tree	*tmp;

	if (root == NULL || f == NULL)
		return ;
	tmp = root;
	if (tmp->left)
		ft_tree_in(tmp->left, f);
	if (tmp->val)
		f(tmp->val);
	if (tmp->right)
		ft_tree_in(tmp->right, f);
}
