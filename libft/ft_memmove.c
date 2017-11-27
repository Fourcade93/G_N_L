/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:25:16 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/16 20:31:22 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = (unsigned char*)dest;
	psrc = (const unsigned char*)src;
	if (pdest < psrc)
		while (len--)
			*pdest++ = *psrc++;
	else
	{
		pdest += len;
		psrc += len;
		while (len--)
			*--pdest = *--psrc;
	}
	return (dest);
}
