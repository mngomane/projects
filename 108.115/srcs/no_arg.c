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

#include <unistd.h>
#include "ft_ls.h"

void	ft_noarg(t_list *arg)
{
	LCAST(t_var *, arg)->dirp = opendir(".");
	if (LCAST(t_var *, arg)->dirp != NULL)
	{
		while ((LCAST(t_var *, arg)->dp = readdir(LCAST(t_var *, arg)->dirp)) != NULL)
		{
			if (LCAST(t_var *, arg)->dp->d_name[0] != '.')
			{
				write(1, LCAST(t_var *, arg)->dp->d_name, ft_strlen(LCAST(t_var *, arg)->dp->d_name));
				write(1, "    ", 4);
			}
		}
		write(1, "\n", 1);
		closedir(LCAST(t_var *, arg)->dirp);
	}
	else
		ft_puterr(UNKNOWN_ERROR);
}
