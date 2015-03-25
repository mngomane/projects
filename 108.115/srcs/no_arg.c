/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 17:12:15 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 17:45:44 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_noarg(t_list *arg)
{
	LVALUE(t_var *, arg)->dirp = opendir(".");
	if (LVALUE(t_var *, arg)->dirp != NULL)
	{
		LVALUE(t_var *, arg)->dp = readdir(LVALUE(t_var *, arg)->dirp);
		while (LVALUE(t_var *, arg)->dp != NULL)
		{
			if (LVALUE(t_var *, arg)->dp->d_name[0] != '.')
			{
				ft_putstr(LVALUE(t_var *, arg)->dp->d_name);
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
	else
		ft_puterr(UNKNOWN_ERROR);
}
