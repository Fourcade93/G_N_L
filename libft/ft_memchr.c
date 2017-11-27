/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:37:04 by fmallaba          #+#    #+#             */
/*   Updated: 2017/10/28 00:58:01 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*s;

	s = (unsigned char*)str;
	while (n--)
	{
		if (*s == (unsigned char)c)
			return ((void*)s);
		s++;
	}
	return (0);
}
