/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:39:33 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/05 17:25:58 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *a, const char *b)
{
	if ((unsigned char)*a && (unsigned char)*b)
		while ((unsigned char)*a && (unsigned char)*b)
		{
			if ((unsigned char)*a != (unsigned char)*b)
				return ((unsigned char)*a - (unsigned char)*b);
			a++;
			b++;
		}
	return ((unsigned char)*a - (unsigned char)*b);
}
