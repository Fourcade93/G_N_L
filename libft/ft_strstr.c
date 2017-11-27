/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:25:46 by fmallaba          #+#    #+#             */
/*   Updated: 2017/10/30 15:37:02 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *a, const char *b)
{
	size_t	len;

	if (!*b)
		return ((char*)a);
	len = ft_strlen(b);
	while (*a)
	{
		if (ft_strncmp(a, b, len) == 0)
			return ((char*)a);
		a++;
	}
	return (0);
}
