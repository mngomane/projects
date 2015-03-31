/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:36:49 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 23:36:49 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>
#include "ft_ls.h"

static void		stat_error(t_file **file, void *name)
{
	free((*file)->stat);
	(*file)->stat = (void *)0;
	ft_puterr(BIN_NAME);
	ft_puterr(": ");
	perror(name);
}

static void		set_infos(t_file **file, void *name, quad_t *block)
{
	if (block && (S_ISREG((*file)->stat->st_mode) ||
		S_ISLNK((*file)->stat->st_mode)))
		*block += (*file)->stat->st_blocks;
	(*file)->passwd = getpwuid((*file)->stat->st_uid);
	(*file)->group = getgrgid((*file)->stat->st_gid);
	if (S_ISLNK((*file)->stat->st_mode) &&
		((*file)->link = (void *)ft_memalloc(sizeof(char) << 9)))
	{
		if (readlink((char *)name, (char *)((*file)->link), 1 << 9) == -1 &&
			!ft_strncmp(strerror(ENOENT), E_ENOENT_MSG, sizeof(E_ENOENT_MSG)))
		{
			if (!ft_strcmp(name, "stdin"))
				(*file)->link = ft_strcat((*file)->link, "fd/0");
			if (!ft_strcmp(name, "stdout"))
				(*file)->link = ft_strcat((*file)->link, "fd/1");
			if (!ft_strcmp(name, "stderr"))
				(*file)->link = ft_strcat((*file)->link, "fd/2");
		}
	}
}

t_file			*new_file(void *path, void *name, u_char flags, quad_t *block)
{
	t_file		*file;
	int			(*ft_stat)(const char *, struct stat *);

	if ((file = (t_file *)ft_memalloc(sizeof(t_file))) != (void *)0)
	{
		if ((file->stat = (t_stat *)ft_memalloc(sizeof(t_stat))))
		{
			ft_stat = (F_LONG(flags) ? lstat : stat);
			if ((ft_stat(ft_strjoin(path, name), file->stat) == -1) &&
				ft_strncmp(strerror(ELOOP), E_ELOOP_MSG, sizeof(E_ELOOP_MSG)))
				stat_error(&file, name);
			else
				set_infos(&file, name, block);
		}
		file->name = ft_strdup(name);
	}
	return (file);
}
