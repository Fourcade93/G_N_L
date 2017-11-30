/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 23:51:12 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/28 16:32:00 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	write_num(char *str, int sign)
{
	long long	res;
	long long	tmp;

	res = 0;
	while (*str > 47 && *str < 58)
	{
		tmp = res;
		res = res * 10 + (*str++ - '0');
		if (tmp > res && sign == 1)
			return (-1);
		else if (tmp > res && sign == -1)
			return (0);
	}
	return ((int)res * sign);
}

int			ft_atoi(char *str)
{
	int			sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	(*str == '-') ? sign = -1 : sign;
	(*str == '-' || *str == '+') ? str++ : str;
	return (write_num(str, sign));
}
