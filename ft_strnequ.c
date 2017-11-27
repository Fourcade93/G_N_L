/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:46:55 by fmallaba          #+#    #+#             */
/*   Updated: 2017/10/31 15:50:08 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		if (*s1 != *s2)
			return (0);
		while (n && *s1 == *s2 && *s1 && *s2)
		{
			n--;
			s1++;
			s2++;
		}
		if (!n || !*s2)
			return (1);
	}
	return (0);
}
