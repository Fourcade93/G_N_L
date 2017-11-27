/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:50:52 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/05 18:44:24 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(src);
	len++;
	tmp = (char*)malloc(sizeof(char) * len);
	if (tmp)
	{
		tmp[len] = '\0';
		while (len--)
			tmp[len] = src[len];
	}
	else
		return (NULL);
	return (tmp);
}
