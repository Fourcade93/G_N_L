/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:21:52 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/05 18:24:31 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s));
	i = 0;
	if (tmp)
		while (*s)
		{
			tmp[i] = f(i, *s++);
			i++;
		}
	else
		return (NULL);
	tmp[i] = '\0';
	return (tmp);
}
