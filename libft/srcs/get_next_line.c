/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 09:04:03 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/04 10:55:57 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*dup_and_del(char *dest, char **src)
{
	dest = ft_strdup(*src);
	ft_strdel(src);
	return (dest);
}

static char	*malloc_more(char *str, size_t size)
{
	char	*temp;
	size_t	len;

	if (ft_strlen(str) == 0)
		str = ft_strnew(size + 1);
	else
	{
		len = ft_strlen(str);
		temp = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strnew(len + size + 1);
		str = ft_strcpy(str, temp);
		free(temp);
	}
	return (str);
}

static void	copy_buf(char **line, char **buf, char *temp, int i)
{
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, temp, i);
	if (temp[i] != 0)
	{
		if (!temp[i + 1])
			ft_strdel(buf);
		else
		{
			ft_strdel(&temp);
			temp = ft_strdup(*buf + i + 1);
			ft_strdel(buf);
			*buf = ft_strdup(temp);
		}
	}
	else
		ft_strdel(buf);
	ft_strdel(&temp);
}

static int	read_from_file(const int fd, char **buf, char **line)
{
	unsigned long	i;
	int				ret;
	char			*temp;

	i = 0;
	ret = -10;
	while (*buf + i)
	{
		temp = ft_strdup(*buf);
		while ((temp[i]) && (temp[i] != '\n'))
			i++;
		if ((temp[i] == '\n') || ((temp[i] == '\0') && (ret == 0)))
		{
			copy_buf(line, buf, temp, i);
			return (1);
		}
		if (!(temp = malloc_more(temp, BUFF_SIZE)))
			return (-1);
		if ((ret = read(fd, temp + i, BUFF_SIZE)) == -1)
			return (-1);
		if (temp[i] != 0)
			ft_strdel(buf);
		*buf = dup_and_del(*buf, &temp);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf = NULL;
	int			i;
	int			ret;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	i = 0;
	if (!buf)
	{
		buf = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, buf, BUFF_SIZE)) < 1)
			ft_strdel(&buf);
		if (ret == 0)
			return (0);
		if (ret == -1)
			return (-1);
	}
	if ((i = read_from_file(fd, &buf, line)) == -1)
		return (-1);
	if (i == 1)
		return (1);
	return (0);
}
