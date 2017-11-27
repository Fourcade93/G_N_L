/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:23:32 by fmallaba          #+#    #+#             */
/*   Updated: 2017/10/31 19:49:59 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*arr;
	size_t			i;

	arr = malloc(size);
	if (!arr)
		return (NULL);
	i = 0;
	while (size--)
		arr[i++] = 0;
	return (arr);
}
