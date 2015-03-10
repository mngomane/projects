/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_lfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 19:43:55 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 19:42:17 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

void		ft_arg(t_list *arg)
{
	write(1, arg->dir->fname, ft_strlen(arg->dir->fname));
	write(1, "    ", 4);
}

void		sub_nofile(t_list *arg)
{
	arg->dir->dirp = opendir(".");
	if (arg->dir->dirp != NULL)
	{
		while ((arg->dir->dp = readdir(arg->dir->dirp)) != NULL)
		{
			if (stat(arg->dir->dp->d_name, &(arg->dir->filestat)) < 0)
				write(2, "\nStat Error sub_nolfile\n", 24);
			else if (arg->dir->dp->d_name[0] != '.')
			{
				arg->dir->fname = arg->dir->dp->d_name;
				ft_arg(arg);
			}
		}
		(void)closedir(arg->dir->dirp);
	}
}

void		sub_nofile2(t_list *arg)
{
	arg->dir->dirp = opendir("../.");
	if (arg->dir->dirp != NULL)
	{
		while ((arg->dir->dp = readdir(arg->dir->dirp)) != NULL)
		{
			if (stat(arg->dir->dp->d_name, &(arg->dir->filestat)) < 0)
				write(2, "\nStat Error sub_nolfile\n", 24);
			else if (arg->dir->dp->d_name[0] != '.')
			{
				arg->dir->fname = arg->dir->dp->d_name;
				ft_arg(arg);
			}
		}
		(void)closedir(arg->dir->dirp);
	}
}

void		no_file(t_list *arg, void (*fct[3])(t_list *), int ac)
{
	if (ac < 2 || arg->dir->fname == NULL)
		sub_nofile(arg);
	else
		apptol(arg, fct);
	write(1, "\n", 1);
}
