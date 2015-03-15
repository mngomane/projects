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

#include "ft_ls.h"

static void		apptoone(t_list *arg)
{
	while (arg)
	{
		if (ft_strcmp(LCAST(t_var *, arg)->fname, "."))
		{
			if (stat(LCAST(t_var *, arg)->fname,
				&(LCAST(t_var *, arg)->filestat)) < 0)
			{
				write(2, "ft_ls: ", 7);
				ft_puterr(LCAST(t_var *, arg)->fname);
				write(2, ": No such file or directory\n", 28);
			}
		}
		arg = arg->next;
	}
}

static void		apptotwo(t_list *arg, void (*fct[2])(t_list *))
{
	while (arg)
	{
		if (ft_strcmp(LCAST(t_var *, arg)->fname, ".") &&
			ft_strcmp(LCAST(t_var *, arg)->fname, ".."))
		{
			if (stat(LCAST(t_var *, arg)->fname,
				&(LCAST(t_var *, arg)->filestat)) >= 0)
			{
				if (S_ISDIR(LCAST(t_var *, arg)->filestat.st_mode))
					appdir(arg, fct);
				else if (fct[0] == sub_nolfile)
					ft_larg(arg);
				else
				{
					ft_putstr(LCAST(t_var *, arg)->fname);
					write(1, "    ", 4);
				}
			}
		}
		arg = arg->next;
	}
}

static void		apptothree(t_list *arg)
{
	while (arg)
	{
		if (!ft_strcmp(LCAST(t_var *, arg)->fname, "."))
		{
			if (LCAST(t_var *, arg)->ac > 1)
				write(1, "\n.:\n", 4);
			ft_putstr(LCAST(t_var *, arg)->fname);
			write(1, "    ", 4);
		}
		arg = arg->next;
	}
}

void			appdir(t_list *arg, void (*fct[2])(t_list *))
{
	char	*dir_name;

	dir_name = LCAST(t_var *, arg)->fname;
	LCAST(t_var *, arg)->dirp = opendir(LCAST(t_var *, arg)->fname);
	if (LCAST(t_var *, arg)->dirp != NULL)
	{
		LCAST(t_var *, arg)->dp = readdir(LCAST(t_var *, arg)->dirp);
		while (LCAST(t_var *, arg)->dp != NULL)
		{
			if (stat(dir_name, &(LCAST(t_var *, arg)->filestat)) < 0)
				ft_puterr(UNKNOWN_ERROR);
			else if (LCAST(t_var *, arg)->dp->d_name[0] != '.')
			{
				LCAST(t_var *, arg)->fname = LCAST(t_var *, arg)->dp->d_name;
				if (fct[0] == sub_nolfile)
					ft_larg(arg);
				else
				{
					ft_putstr(LCAST(t_var *, arg)->fname);
					write(1, "    ", 4);
				}
			}
			LCAST(t_var *, arg)->dp = readdir(LCAST(t_var *, arg)->dirp);
		}
		closedir(LCAST(t_var *, arg)->dirp);
	}
}

void			apptol(t_list *arg, void (*fct[2])(t_list *))
{
	t_list	*save;

	save = arg;
	apptoone(arg);
	arg = save;
	apptotwo(arg, fct);
	arg = save;
	apptothree(arg);
	arg = save;
	while (arg)
	{
		if (!ft_strcmp(LCAST(t_var *, arg)->fname, ".."))
		{
			if (LCAST(t_var *, arg)->ac > 1)
				write(1, "\n..:\n", 5);
			(fct[1])(arg);
		}
		arg = arg->next;
	}
	arg = save;
}
