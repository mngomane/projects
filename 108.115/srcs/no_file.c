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

#include "ft_ls.h"

void		sub_nofile(t_list *arg)
{
	LVALUE(t_var *, arg)->dirp = opendir(".");
	if (LVALUE(t_var *, arg)->dirp != NULL)
	{
		LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
		while (LVALUE(t_var *, arg)->dp != NULL)
		{
			if (stat(LVALUE(t_var *, arg)->dp->d_name,
				&(LVALUE(t_var *, arg)->filestat)) < 0)
				ft_puterr(FAILED_STAT);
			if (LVALUE(t_var *, arg)->dp->d_name[0] != '.')
			{
				LVALUE(t_var *, arg)->fname = LVALUE(t_var *, arg)->dp->d_name;
				ft_putstr(LVALUE(t_var *, arg)->fname);
				LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
				if (LVALUE(t_var *, arg)->dp)
					write(1, "    ", 4);
			}
			else
				LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
			if (!LVALUE(t_var *, arg)->dp)
				write(1, "\n", 1);
		}
		closedir(LVALUE(t_var *, arg)->dirp);
	}
}

void		sub_nofile2(t_list *arg)
{
	LVALUE(t_var *, arg)->dirp = opendir("../.");
	if (LVALUE(t_var *, arg)->dirp != NULL)
	{
		LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
		while (LVALUE(t_var *, arg)->dp != NULL)
		{
			if (stat(LVALUE(t_var *, arg)->dp->d_name,
				&(LVALUE(t_var *, arg)->filestat)) < 0)
				ft_puterr(FAILED_STAT);
			if (LVALUE(t_var *, arg)->dp->d_name[0] != '.')
			{
				LVALUE(t_var *, arg)->fname = LVALUE(t_var *, arg)->dp->d_name;
				ft_putstr(LVALUE(t_var *, arg)->fname);
				LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
				if (LVALUE(t_var *, arg)->dp)
					write(1, "    ", 4);
			}
			else
				LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
			if (!LVALUE(t_var *, arg)->dp)
				write(1, "\n", 1);
		}
		closedir(LVALUE(t_var *, arg)->dirp);
	}
}

void		no_file(t_list *arg, void (*fct[2])(t_list *), int ac)
{
	if (ac < 2 || LVALUE(t_var *, arg)->fname == NULL)
		sub_nofile(arg);
	else
		apptol(arg, fct);
}
