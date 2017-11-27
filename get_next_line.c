/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:38:01 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/27 21:46:31 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void	cut_buff(char (*buf)[BUFF_SIZE + 1], char **line, char **tmp)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*buf)[i] != '\n')
		i++;
	if ((i == 0 && !(*tmp)) || i > 0)
		*line = ft_strsub((*buf), 0, i);
	if (*tmp)
	{
		temp = ft_strsub(*buf, 0, i);
		*line = ft_strjoin((*tmp), temp);
		ft_strdel(&(*tmp));
		ft_strdel(&temp);
	}
	ft_memmove(&(*buf)[0], &(*buf)[i + 1], BUFF_SIZE - i);
}

void	get_line_from_last(char **line, char (*buf)[BUFF_SIZE + 1], char **tmp)
{
	int	len;

	len = 0;
	while ((*buf)[len] && (*buf)[len] != '\n')
		len++;
	if (!len)
		*tmp = NULL;
	*line = ft_strsub(*buf, 0, len);
	if (ft_strchr(*buf, 10))
	{
		ft_bzero(&(*buf)[0], len);
		ft_memmove(&(*buf)[0], &(*buf)[len + 1], BUFF_SIZE - len);
	}
	else
	{
		*tmp = *line;
		ft_bzero(*buf, BUFF_SIZE + 1);
	}
}

void	get_next_line_help(char **line, char (*buf)[BUFF_SIZE + 1], char **tmp)
{
	if (!(*tmp))
	{
		*tmp = ft_strdup(*buf);
		*line = *tmp;
	}
	else
	{
		*line = ft_strjoin(*tmp, *buf);
		ft_strdel(&(*tmp));
		*tmp = *line;
	}
	ft_bzero(*buf, BUFF_SIZE + 1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		*tmp;
	static char	buf[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	tmp = NULL;
	if (ft_strlen(buf))
		get_line_from_last(&(*line), &buf, &tmp);
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0 && !ft_strchr(buf, 10))
	{
		ft_bzero(&buf[ret], BUFF_SIZE);
		get_next_line_help(&(*line), &buf, &tmp);
	}
	if (ft_strchr(buf, 10))
		cut_buff(&buf, &(*line), &tmp);
	if (ret < 0)
		return (-1);
	if (ret == 0 && tmp == NULL)
		return (0);
	return (1);
}
