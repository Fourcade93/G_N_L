/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 01:02:36 by fmallaba          #+#    #+#             */
/*   Updated: 2017/10/28 01:06:05 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *f;
	const unsigned char *s;

	f = s1;
	s = s2;
	while (n--)
	{
		if (*f != *s)
			return (*f - *s);
		f++;
		s++;
	}
	return (0);
}
