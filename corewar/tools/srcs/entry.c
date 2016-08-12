/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 04:45:26 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/02 04:45:26 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "tools.h"

static size_t	in_word(char c)
{
	if (c >= '!' && c <= '~')
		return (1);
	return (0);
}

static int		secu_malloc(char **str, size_t len)
{
	if ((*str = (char *)malloc(sizeof(char) * len)) == NULL)
	{
		ft_putstr_fd("malloc failed [entry.c]\n", 2);
		return (0);
	}
	return (1);
}

static char		*sub_trim(char *str, char *tmp, size_t len, size_t i)
{
	if ((tmp = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
	{
		ft_putstr_fd("malloc failed [entry.c]\n", 2);
		return (NULL);
	}
	i = 0;
	while (i < READ_MAX && i < len)
	{
		tmp[i] = str[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char		*trim_entry(char *str, size_t (*w_fct)(char))
{
	char		*tmp;
	size_t		i;
	size_t		len;

	tmp = NULL;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	while (!w_fct(*str) && *str != '\0')
	{
		++str;
		--len;
	}
	if (len > 0)
		i = len - 1;
	else
		return (NULL);
	while (!w_fct(str[i]) && i > 1)
	{
		--i;
		--len;
	}
	tmp = sub_trim(str, tmp, len, i);
	return (tmp);
}

static int		sub_fill(t_entry *ent, char (*buffer)[READ_MAX + 1], ssize_t *ret)
{
	size_t		i;

	i = 0;
	(*buffer)[*ret] = '\0';
	if (*ret == READ_MAX + 1)
	{
		ft_putstr_fd("File name too long !\n", 2);
		while ((*ret = read(ent->fd, ent->erase, 4096)) >= 0
				&& ent->erase[4095] != 0)
			;
		return (1);
	}
	if (ent->save != NULL)
		free(ent->save);
	if (!secu_malloc(&(ent->save), (size_t)(*ret) - 1))
		return (0);
	while (i < (size_t)(*ret) - 1)
	{
		ent->save[i] = (*buffer)[i];
		++i;
	}
	ent->save[i] = '\0';
	ent->save = trim_entry(ent->save, in_word);
	return (1);
}

int				fill_entry(t_entry *ent)
{
	ssize_t		ret;
	char		buffer[READ_MAX + 1];

	if ((ret = read(ent->fd, buffer, READ_MAX + 1)) > 0
		&& buffer[0] != ent->end && !sub_fill(ent, &buffer, &ret))
		return (0);
	if (ret == -1)
	{
		ft_putstr_fd("Something strange happened. ", 2);
		ft_putstr_fd("To avoid all risks asm will be stopped.\nExit\n", 2);
		return (0);
	}
	if (ret == 0)
	{
		ft_puts("\033[1D\033[K\nexit\n");
		exit(ent->exit_status);
	}
	return (1);
}
