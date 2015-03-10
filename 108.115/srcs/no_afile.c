/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_afile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 20:49:18 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 19:40:59 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

void		sub_noafile(t_list *arg)
{
	arg->dir->dirp = opendir(".");
	if (arg->dir->dirp != NULL)
	{
		while ((arg->dir->dp = readdir(arg->dir->dirp)) != NULL)
		{
			if (stat(arg->dir->dp->d_name, &(arg->dir->filestat)) < 0)
				write(2, "\nStat Error sub_nolfile\n", 24);
			else
			{
				arg->dir->fname = arg->dir->dp->d_name;
				ft_arg(arg);
			}
		}
		(void)closedir(arg->dir->dirp);
	}
}

void		sub_noafile2(t_list *arg)
{
	arg->dir->dirp = opendir("../.");
	if (arg->dir->dirp != NULL)
	{
		while ((arg->dir->dp = readdir(arg->dir->dirp)) != NULL)
		{
			if (stat(arg->dir->dp->d_name, &(arg->dir->filestat)) < 0)
				write(2, "\nStat Error sub_nolfile\n", 24);
			else
			{
				arg->dir->fname = arg->dir->dp->d_name;
				ft_arg(arg);
			}
		}
		(void)closedir(arg->dir->dirp);
	}
}

void		no_afile(t_list *arg, void (*fct[3])(t_list *), int ac)
{
	if (ac < 3 || arg->dir->fname == NULL)
		sub_noafile(arg);
	else
		apptol(arg, fct);
	write(1, "\n", 1);
}
