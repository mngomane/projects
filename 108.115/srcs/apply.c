/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 20:07:20 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 19:55:29 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

static void		apptoone(t_list *arg)
{
	while (arg)
	{
		if (ft_strcmp(arg->dir->fname, "."))
		{
			if (stat(arg->dir->fname, &(arg->dir->filestat)) < 0)
			{
				write(2, "ft_ls: ", 7);
				write(2, arg->dir->fname, ft_strlen(arg->dir->fname));
				write(2, ": No such file or directory\n", 28);
			}
		}
		arg = arg->next;
	}
}

static void		apptotwo(t_list *arg, void (*fct[3])(t_list *))
{
	while (arg)
	{
		if (ft_strcmp(arg->dir->fname, ".") && ft_strcmp(arg->dir->fname, ".."))
		{
			if (stat(arg->dir->fname, &(arg->dir->filestat)) >= 0)
			{
				if (S_ISDIR(arg->dir->filestat.st_mode))
					appdir(arg, fct);
				else
					(fct[0])(arg);
			}
		}
		arg = arg->next;
	}
}

static void		apptothree(t_list *arg, void (*fct[3])(t_list *))
{
	while (arg)
	{
		if (!ft_strcmp(arg->dir->fname, "."))
		{
			if (arg->dir->ac > 1)
				write(1, "\n.:\n", 4);
			(fct[1])(arg);
		}
		arg = arg->next;
	}
}

void			appdir(t_list *arg, void (*fct[3])(t_list *))
{
	char	*dir_name;

	dir_name = arg->dir->fname;
	arg->dir->dirp = opendir(arg->dir->fname);
	if (arg->dir->dirp != NULL)
	{
		while ((arg->dir->dp = readdir(arg->dir->dirp)) != NULL)
		{
			if (stat(dir_name, &(arg->dir->filestat)) < 0)
				write(2, "\nStat Error in appdir (apply.c)\n", 32);
			else if (arg->dir->dp->d_name[0] != '.')
			{
				arg->dir->fname = arg->dir->dp->d_name;
				(fct[0])(arg);
			}
		}
		(void)closedir(arg->dir->dirp);
	}
}

void			apptol(t_list *arg, void (*fct[3])(t_list *))
{
	t_list	*save;

	save = arg;
	apptoone(arg);
	arg = save;
	apptotwo(arg, fct);
	arg = save;
	apptothree(arg, fct);
	arg = save;
	while (arg)
	{
		if (!ft_strcmp(arg->dir->fname, ".."))
		{
			if (arg->dir->ac > 1)
				write(1, "\n..:\n", 5);
			(fct[2])(arg);
		}
		arg = arg->next;
	}
	arg = save;
}
