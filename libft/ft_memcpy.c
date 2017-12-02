/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 03:04:24 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/30 22:52:45 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = (unsigned char*)dest;
	psrc = (unsigned char *)src;
	while (len--)
		*pdest++ = *psrc++;
	return (dest);
}
