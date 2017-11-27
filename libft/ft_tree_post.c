/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_post.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:10:35 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/09 20:10:37 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_post(t_tree *root, void (*f)(int))
{
	t_tree	*tmp;

	if (root == NULL || f == NULL)
		return ;
	tmp = root;
	if (tmp->left)
		ft_tree_post(tmp->left, f);
	if (tmp->right)
		ft_tree_post(tmp->right, f);
	if (tmp->val)
		f(tmp->val);
}
