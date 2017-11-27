/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 01:08:41 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/13 13:07:00 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int		get_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
	{
		i = 2;
		n = 147483648;
	}
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*make_str(char *ret, int n, int len, int sign)
{
	ret[len] = '\0';
	if (n == -2147483648)
	{
		sign = 2;
		ret[0] = '-';
		ret[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		ret[0] = '-';
		sign = 1;
		n = -n;
	}
	while (len-- != sign)
	{
		ret[len] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		sign;

	len = get_len(n);
	sign = 0;
	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret = make_str(ret, n, len, sign);
	return (ret);
}
