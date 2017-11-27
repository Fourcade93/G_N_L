/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 23:33:57 by fmallaba          #+#    #+#             */
/*   Updated: 2017/10/27 18:37:59 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int val, size_t len)
{
	unsigned char	*c;

	c = ptr;
	while (len--)
	{
		*c = (unsigned char)val;
		c++;
	}
	return (ptr);
}
