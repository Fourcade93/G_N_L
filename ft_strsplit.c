/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 22:19:45 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/23 16:51:24 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;

	i = 1;
	while (*s)
		if (*s++ != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	return (i);
}

static char		*create_str(char const *s, char c)
{
	size_t	len;
	char	*str;

	len = 0;
	while (*s && *s++ != c)
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	return (str);
}

static char		**clean_arr(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		ft_strdel(&arr[i++]);
	free(arr);
	arr = NULL;
	return (NULL);
}

static char		**add_str(char **arr, char const *s, char c, size_t num_of_str)
{
	size_t	s_pos;
	size_t	num_of_symb;

	s_pos = 0;
	while (s[s_pos])
	{
		if (s[s_pos] != c)
		{
			num_of_symb = 0;
			if (!(arr[num_of_str] = create_str(&s[s_pos], c)))
				return (clean_arr(arr, num_of_str));
			while (s[s_pos] && s[s_pos] != c)
				arr[num_of_str][num_of_symb++] = s[s_pos++];
			arr[num_of_str][num_of_symb] = '\0';
			s_pos--;
			num_of_str++;
		}
		s_pos++;
	}
	arr[num_of_str] = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	words;
	size_t	num_of_str;

	num_of_str = 0;
	if (s == NULL)
		return (NULL);
	words = count_word(s, c);
	if (!*s || words == 1)
	{
		arr = (char**)malloc(1);
		if (!arr)
			return (NULL);
		arr[0] = NULL;
	}
	else
	{
		arr = (char**)malloc(sizeof(char*) * words);
		if (!arr)
			return (NULL);
		arr = add_str(arr, s, c, num_of_str);
	}
	return (arr);
}
