/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 02:28:46 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/30 02:28:46 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_ls.h"

char			*init_time(t_stat *cstat)
{
	size_t		index;
	char		*tmp_time;
	char		*new_time;

	index = 4;
	if((new_time = (char *)ft_memalloc(sizeof(char) << 4)))
	{
		tmp_time = ctime(&(cstat->st_mtime));
		while (index < 16)
		{
			new_time[index - 4] = tmp_time[index];
			++index;
		}
		new_time[index] = '\0';
		return (new_time);
	}
	return ((void *)0);
}

ssize_t			display_rights(t_stat *cstat)
{
	ssize_t		ret;

	ret = 0;
	ret += write(1, entry_type(cstat->st_mode), 1);
	ret += write(1, (cstat->st_mode & S_IRUSR) ? "r" : "-", 1);
	ret += write(1, (cstat->st_mode & S_IWUSR) ? "w" : "-", 1);
	ret += write(1, owner_perm(cstat->st_mode), 1);
	ret += write(1, (cstat->st_mode & S_IRGRP) ? "r" : "-", 1);
	ret += write(1, (cstat->st_mode & S_IWGRP) ? "w" : "-", 1);
	ret += write(1, group_perm(cstat->st_mode), 1);
	ret += write(1, (cstat->st_mode & S_IROTH) ? "r" : "-", 1);
	ret += write(1, (cstat->st_mode & S_IWOTH) ? "w" : "-", 1);
	ret += write(1, other_perm(cstat->st_mode), 1);
	return (ret);
}
