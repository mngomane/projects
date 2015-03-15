/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_lfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 19:43:55 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 20:11:12 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

void		sub_nolfile(t_list *arg)
{
	LCAST(t_var *, arg)->dirp = opendir(".");
	if (LCAST(t_var *, arg)->dirp != NULL)
	{
		while ((LCAST(t_var *, arg)->dp = readdir(LCAST(t_var *, arg)->dirp)) != NULL)
		{
			if (stat(LCAST(t_var *, arg)->dp->d_name, &(LCAST(t_var *, arg)->filestat)) < 0)
				write(2, "\nStat Error sub_nolfile\n", 24);
			else if (LCAST(t_var *, arg)->dp->d_name[0] != '.')
			{
				LCAST(t_var *, arg)->fname = LCAST(t_var *, arg)->dp->d_name;
				ft_larg(arg);
			}
		}
		(void)closedir(LCAST(t_var *, arg)->dirp);
	}
}

void		sub_nolfile2(t_list *arg)
{
	LCAST(t_var *, arg)->dirp = opendir("../.");
	if (LCAST(t_var *, arg)->dirp != NULL)
	{
		while ((LCAST(t_var *, arg)->dp = readdir(LCAST(t_var *, arg)->dirp)) != NULL)
		{
			if (stat(LCAST(t_var *, arg)->dp->d_name, &(LCAST(t_var *, arg)->filestat)) < 0)
				write(2, "\nStat Error sub_nolfile\n", 24);
			else if (LCAST(t_var *, arg)->dp->d_name[0] != '.')
			{
				LCAST(t_var *, arg)->fname = LCAST(t_var *, arg)->dp->d_name;
				ft_larg(arg);
			}
		}
		(void)closedir(LCAST(t_var *, arg)->dirp);
	}
}

void		no_lfile(t_list *arg, void (*fct[3])(t_list *), int ac)
{
	if (ac < 3 || LCAST(t_var *, arg)->fname == NULL)
		sub_nolfile(arg);
	else
		apptol(arg, fct);
}
