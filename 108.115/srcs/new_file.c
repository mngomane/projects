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

t_file			*new_file(void *path, void *name, u_char flags)
{
	t_file		*file;
	int			(*ft_stat)(const char *, struct stat *);

	if ((file = (t_file *)ft_memalloc(sizeof(t_file))) != (void *)0)
	{
		if ((file->stat = (t_stat *)ft_memalloc(sizeof(t_stat))))
		{
			ft_stat = (F_LONG(flags) ? lstat : stat);
			if (ft_stat(ft_strjoin(path, name), file->stat) == -1)
				stat_error(&file, name);
			else
			{
				file->passwd = getpwuid(file->stat->st_uid);
				file->group = getgrgid(file->stat->st_uid);
				if (S_ISLNK(file->stat->st_mode) &&
					(file->link = (void *)ft_memalloc(sizeof(char) << 9)))
					readlink((char *)name, (char *)(file->link), 1 << 9);
			}
		}
		file->name = ft_strdup(name);
	}
	return (file);
}
