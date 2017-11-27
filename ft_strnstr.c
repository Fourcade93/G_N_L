/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:32:49 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/05 18:57:05 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t len)
{
	size_t	n;

	if (*b == '\0')
		return ((char*)a);
	if (*a == '\0')
		return (NULL);
	n = ft_strlen(b);
	while (len && *a)
	{
		if (len < n)
			return (NULL);
		else if (ft_strncmp(a, b, n) == 0)
			return ((char*)a);
		a++;
		len--;
	}
	return (NULL);
}
