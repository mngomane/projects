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
		if (ft_strcmp(LVALUE(t_var *, arg)->fname, "."))
		{
			if (stat(LVALUE(t_var *, arg)->fname,
				&(LVALUE(t_var *, arg)->filestat)) < 0)
			{
				ft_puterr(NAME);
				ft_puterr(LVALUE(t_var *, arg)->fname);
				ft_puterr(NO_FORDIR);
			}
		}
		arg = arg->next;
	}
}

static void		appdir(t_list *arg, void (*fct[2])(t_list *))
{
	char	*dir_name;

	dir_name = LVALUE(t_var *, arg)->fname;
	LVALUE(t_var *, arg)->dirp = opendir(LVALUE(t_var *, arg)->fname);
	if (LVALUE(t_var *, arg)->dirp != (void *)0)
	{
		LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
		while (LVALUE(t_var *, arg)->dp != (void *)0)
		{
			if (stat(dir_name, &(LVALUE(t_var *, arg)->filestat)) < 0)
				ft_puterr(UNKNOWN_ERROR);
			else if (LVALUE(t_var *, arg)->dp->d_name[0] != '.')
			{
				LVALUE(t_var *, arg)->fname = LVALUE(t_var *, arg)->dp->d_name;
				if (fct[0] == sub_nolfile)
					ft_larg(arg);
				else
					ft_printf("%s    ", LVALUE(t_var *, arg)->fname);
			}
			LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
		}
		closedir(LVALUE(t_var *, arg)->dirp);
	}
}

static void		apptotwo(t_list *arg, void (*fct[2])(t_list *))
{
	while (arg)
	{
		if (ft_strcmp(LVALUE(t_var *, arg)->fname, ".") &&
			ft_strcmp(LVALUE(t_var *, arg)->fname, ".."))
		{
			if (stat(LVALUE(t_var *, arg)->fname,
				&(LVALUE(t_var *, arg)->filestat)) >= 0)
			{
				if (S_ISDIR(LVALUE(t_var *, arg)->filestat.st_mode))
					appdir(arg, fct);
				else if (fct[0] == sub_nolfile)
					ft_larg(arg);
				else
					ft_printf("%s    ", LVALUE(t_var *, arg)->fname);
			}
		}
		arg = arg->next;
	}
}

static void		apptothree(t_list *arg)
{
	while (arg)
	{
		if (!ft_strcmp(LVALUE(t_var *, arg)->fname, "."))
		{
			if (LVALUE(t_var *, arg)->ac > 1)
				write(1, ".:\n", 3);
			ft_putstr(LVALUE(t_var *, arg)->fname);
		}
		arg = arg->next;
		if (arg && ft_strcmp(LVALUE(t_var *, arg)->fname, "."))
			write(1, "    ", 4);
		else
			write(1, "\n", 1);
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
		if (!ft_strcmp(LVALUE(t_var *, arg)->fname, ".."))
		{
			if (LVALUE(t_var *, arg)->ac > 1)
				write(1, "\n..:\n", 5);
			(fct[1])(arg);
		}
		arg = arg->next;
	}
	arg = save;
}
