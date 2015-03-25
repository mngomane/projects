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

#include "ft_ls.h"

void		sub_noafile(t_list *arg)
{
	LVALUE(t_var *, arg)->dirp = opendir(".");
	if (LVALUE(t_var *, arg)->dirp != (void *)0)
	{
		LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
		while (LVALUE(t_var *, arg)->dp != (void *)0)
		{
			if (stat(LVALUE(t_var *, arg)->dp->d_name,
				&(LVALUE(t_var *, arg)->filestat)) < 0)
				ft_puterr(FAILED_STAT);
			else
			{
				LVALUE(t_var *, arg)->fname = LVALUE(t_var *, arg)->dp->d_name;
				ft_putstr(LVALUE(t_var *, arg)->fname);
			}
			LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
			if (LVALUE(t_var *, arg)->dp)
				write(1, "    ", 4);
			else
				write(1, "\n", 1);
		}
		closedir(LVALUE(t_var *, arg)->dirp);
	}
}

void		sub_noafile2(t_list *arg)
{
	LVALUE(t_var *, arg)->dirp = opendir("../.");
	if (LVALUE(t_var *, arg)->dirp != (void *)0)
	{
		LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
		while (LVALUE(t_var *, arg)->dp != (void *)0)
		{
			if (stat(LVALUE(t_var *, arg)->dp->d_name,
				&(LVALUE(t_var *, arg)->filestat)) < 0)
				ft_puterr(FAILED_STAT);
			else
			{
				LVALUE(t_var *, arg)->fname = LVALUE(t_var *, arg)->dp->d_name;
				ft_putstr(LVALUE(t_var *, arg)->fname);
			}
			LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
			if (LVALUE(t_var *, arg)->dp)
				write(1, "    ", 4);
			else
				write(1, "\n", 1);
		}
		closedir(LVALUE(t_var *, arg)->dirp);
	}
}

void		no_afile(t_list *arg, void (*fct[3])(t_list *), int ac)
{
	if (ac < 3 || LVALUE(t_var *, arg)->fname == (void *)0)
		sub_noafile(arg);
	else
		apptol(arg, fct);
}
