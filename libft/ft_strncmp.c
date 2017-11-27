/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:27:28 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/05 17:28:15 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *a, const char *b, size_t n)
{
	if (n == 0)
		return (0);
	if ((unsigned char)*a && (unsigned char)*b)
		while (--n && (unsigned char)*b && (unsigned char)*a)
		{
			if ((unsigned char)*a != (unsigned char)*b)
				return ((unsigned char)*a - (unsigned char)*b);
			a++;
			b++;
		}
	return ((unsigned char)*a - (unsigned char)*b);
}
