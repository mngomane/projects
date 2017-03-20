/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 23:18:30 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/13 23:18:30 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	seek_len(const char *str, char needle)
{
	char	*origin;
	char	*copy;
	char	*copy2;

	copy = (char *)str;
	origin = copy;
	if (str == NULL)
		return (0);
	if (needle != '\0')
	{
		while ((size_t)(copy - str) < seek_len(str, '\0') && *copy != needle)
			++copy;
		if ((size_t)(copy - str) == seek_len(str, '\0'))
			return (0);
		return (1);
	}
	while (*copy != '\0')
		++copy;
	return ((size_t)(copy - origin));
}

static char		*cursor_realloc(char *dst, char *src)
{
	char	*tmp;
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (dst != NULL)
	{
		tmp = (char *)malloc(seek_len(dst, 0) + seek_len(src, 0) + 1);
		while (dst != NULL && index1 < seek_len(dst, 0))
		{
			tmp[index1] = dst[index1];
			++index1;
		}
	}
	else
		tmp = (char *)malloc(sizeof(char) * (seek_len(src, 0) + 1));
	while (src != NULL && index2 < seek_len(src, 0))
	{
		tmp[index1 + index2] = src[index2];
		++index2;
	}
	tmp[index1 + index2] = '\0';
	return (tmp);
}

static size_t	read_move(int fd, char **cursor, char needle, ssize_t *ret)
{
	char		*tmp;
	size_t		check;

	tmp = NULL;
	check = 0;
	if (needle == '\n')
	{
		while (check < seek_len(*cursor, 0) && (*cursor)[check] != '\n')
			++check;
		return (check);
	}
	check = BUFF_SIZE;
	while (*ret > 0 && !seek_len(tmp, '\n'))
	{
		free(tmp);
		if (check < SECURITY)
			tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		*ret = ((check < SECURITY) ? read(fd, tmp, BUFF_SIZE) : -1);
		if (*ret >= 0 && tmp != NULL)
			tmp[*ret] = '\0';
		if (*ret != 0)
			*cursor = cursor_realloc(*cursor, tmp);
	}
	free(tmp);
	return (seek_len(*cursor, 0));
}

static int		get_core(char **cursor, int fd, ssize_t *ret, char **line)
{
	char		*tmp;

	tmp = NULL;
	if (fd == 1)
	{
		*ret = -1;
		return (-1);
	}
	if (!seek_len(*cursor, '\n'))
	{
		read_move(fd, &tmp, 0, ret);
		if (*ret <= 0)
		{
			free(*cursor);
			*cursor = NULL;
			if (line && *ret == 0 && tmp != NULL)
				*line = ((tmp && tmp[0] != '\0') ? tmp : NULL);
			return ((int)*ret);
		}
		*cursor = cursor_realloc(*cursor, tmp);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*cursor = NULL;
	size_t		index[2];
	ssize_t		ret;

	ret = 1;
	index[0] = 0;
	index[1] = 0;
	if (get_core(&cursor, fd, &ret, line) <= 0)
		return ((int)ret);
	index[1] = read_move(fd, &cursor, '\n', &ret);
	*line = (char *)malloc(index[1] + 1);
	while (++index[0] < index[1] + 1)
	{
		(*line)[index[0] - 1] = *cursor;
		++cursor;
	}
	(*line)[index[0]] = '\0';
	if (*cursor == '\n')
	{
		++cursor;
		cursor = cursor_realloc(NULL, cursor);
	}
	else
		cursor = NULL;
	return (1);
}
