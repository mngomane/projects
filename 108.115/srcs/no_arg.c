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
	LCAST(t_var *, arg)->dirp = opendir(".");
	if (LCAST(t_var *, arg)->dirp != NULL)
	{
		LCAST(t_var *, arg)->dp = readdir(LCAST(t_var *, arg)->dirp);
		while (LCAST(t_var *, arg)->dp != NULL)
		{
			if (LCAST(t_var *, arg)->dp->d_name[0] != '.')
			{
				ft_putstr(LCAST(t_var *, arg)->dp->d_name);
				LCAST(t_var *, arg)->dp = readdir(LCAST(t_var *, arg)->dirp);
				if (LCAST(t_var *, arg)->dp)
					write(1, "    ", 4);
			}
			else
				LCAST(t_var *, arg)->dp = readdir(LCAST(t_var *, arg)->dirp);
			if (!LCAST(t_var *, arg)->dp)
				write(1, "\n", 1);
		}
		closedir(LCAST(t_var *, arg)->dirp);
	}
	else
		ft_puterr(UNKNOWN_ERROR);
}
