/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tree_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:27:27 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/09 19:27:30 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_new_tree_elem(int val)
{
	t_tree	*new;

	new = (t_tree*)malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->val = val;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
