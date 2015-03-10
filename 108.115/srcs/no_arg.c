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
	arg->dir->dirp = opendir(".");
	if (arg->dir->dirp != NULL)
	{
		while ((arg->dir->dp = readdir(arg->dir->dirp)) != NULL)
		{
			if (arg->dir->dp->d_name[0] != '.')
			{
				write(1, arg->dir->dp->d_name, ft_strlen(arg->dir->dp->d_name));
				write(1, "    ", 4);
			}
		}
		write(1, "\n", 1);
		(void)closedir(arg->dir->dirp);
	}
	else
		write(2, "Error (no_arg.c)\n", 17);
}
