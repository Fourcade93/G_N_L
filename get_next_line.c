/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:38:01 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/30 22:30:15 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		delete_elem(t_list **list, int fd)
{
	t_list	*tmp;
	t_list	*buf;
	size_t	nfd;

	tmp = *list;
	nfd = fd;
	if (tmp->content_size == nfd)
	{
		buf = tmp->next;
		free(tmp->content);
		free(tmp);
		*list = buf;
		return (0);
	}
	while (tmp->next && tmp->next->content_size != nfd)
		tmp = tmp->next;
	buf = tmp->next->next;
	free(tmp->next->content);
	free(tmp->next);
	tmp->next = buf;
	return (0);
}

void	get_line(t_list *temp, char **line)
{
	char	*buf;
	int		i;
	int		len;

	buf = (char *)(temp->content);
	len = ft_strlen(buf);
	if (ft_strchr(temp->content, 10))
	{
		i = 0;
		while (buf[i] != '\n')
			i++;
		*line = ft_strsub(buf, 0, i);
		if (len - i == 1)
			ft_bzero(buf, len);
		else
		{
			ft_memmove(buf, &buf[i + 1], len - i);
			ft_bzero(&buf[len - i], i);
		}
	}
	else
	{
		*line = ft_strdup(buf);
		ft_bzero(buf, len);
	}
}

t_list	*get_list(t_list **list, char **tmp, int fd)
{
	t_list	*new;
	t_list	*temp;
	size_t	nfd;

	if (*tmp)
	{
		new = ft_lstnew(*tmp, ft_strlen(*tmp) + 1);
		new->content_size = fd;
		ft_lstadd(&(*list), new);
		free(*tmp);
		*tmp = NULL;
		return (*list);
	}
	temp = *list;
	nfd = fd;
	while (temp && temp->content_size != nfd)
		temp = temp->next;
	return (temp);
}

void	get_next_line_help(char buf[BUFF_SIZE + 1], char **tmp, int ret)
{
	char	*temp;
	char	*temp2;

	temp = ft_strsub(buf, 0, ret);
	if (*tmp)
	{
		temp2 = ft_strjoin(*tmp, temp);
		ft_strdel(&(*tmp));
		ft_strdel(&temp);
		*tmp = temp2;
	}
	else
		*tmp = temp;
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	t_list			*temp;
	static t_list	*list;

	if (fd < 0 || !line)
		return (-1);
	tmp = NULL;
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
		get_next_line_help(buf, &tmp, ret);
	if (ret < 0)
		return (-1);
	temp = get_list(&list, &tmp, fd);
	if (!temp)
		return (0);
	if (ret == 0 && !ft_strlen(temp->content))
		return (delete_elem(&list, fd));
	get_line(temp, &(*line));
	return (1);
}
