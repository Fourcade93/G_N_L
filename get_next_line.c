/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:38:01 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/21 19:04:22 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

void	del_content(void *content, size_t size)
{
	ft_memdel(&content);
	size = 0;
}

int		ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int		cut_buff(char (*buf)[BUFF_SIZE + 1], t_list **list)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*buf)[i] != '\n')
		i++;
	tmp = ft_strsub(*buf, 0, i);
	ft_memmove(&(*buf)[0], &(*buf)[i + 1], BUFF_SIZE - i);
	// ft_putendl(*buf);
	ft_list_pushback(&(*list), ft_lstnew(tmp, i));
	free(tmp);
	return (BUFF_SIZE - i);
}

char	*create_str(t_list *list, int count)
{
	char	*str;

	str = ft_strnew(count);
	ft_putendl(ft_itoa(count));
	while (list)
	{
		str = ft_strncat(str, list->content, list->content_size);
		list = list->next;
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	int			count;
	static	int	len;
	static char	buf[BUFF_SIZE + 1];
	t_list		*list;

	list = NULL;
	count = 0;
	if (len)
	{
		count += ft_strclen(buf, '\n');
		ft_list_pushback(&list, ft_lstnew(ft_strsub(buf, 0, len), count));
	}
	ft_bzero(buf, BUFF_SIZE + 1);
	len = 0;
	while (!len && (ret = read(fd, &buf, BUFF_SIZE)))
	{
		count += ft_strclen(buf, '\n');
		if (ft_strrchr(buf, 10))
			len = cut_buff(&buf, &list);
		else
		{
			ft_list_pushback(&list, ft_lstnew(buf, ft_strlen(buf)));
			ft_bzero(buf, BUFF_SIZE);
		}
	}
	if (!list || ret < 0)
		return (-1);
	*line = create_str(list, count);
	ft_lstdel(&list, &del_content);
	if (ret == 0)
		return (0);
	return (0);
}
