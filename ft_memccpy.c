/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 05:07:54 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/05 18:42:33 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *d, const void *s, int ch, size_t n)
{
	unsigned char		*pd;
	unsigned char		*ps;
	size_t				i;

	pd = (unsigned char*)d;
	ps = (unsigned char*)s;
	i = 0;
	while (i < n && (i == 0 || ps[i - 1] != (unsigned char)ch))
	{
		pd[i] = ps[i];
		i++;
	}
	if (i > 0 && ps[i - 1] == (unsigned char)ch)
		return (pd + i);
	return (NULL);
}
