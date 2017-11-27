/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:12:01 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/04 22:14:45 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	const char	*c;

	c = 0;
	while (*str)
	{
		if (*str == (char)ch)
			c = str;
		str++;
	}
	if (*str == (char)ch)
		c = str;
	return ((char*)c);
}
