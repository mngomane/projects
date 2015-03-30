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

#include "ft_ls.h"

static char		*iforest(mode_t mode)
{
	if (mode & S_IFREG)
		return ("-");
	if (mode & S_IFLNK)
		return ("l");
	if (mode & S_IFCHR)
		return ("c");
	if (mode & S_IFIFO)
		return ("p");
	if (mode & S_IFDIR)
		return ("d");
	if (mode & S_IFBLK)
		return ("b");
	if (mode & S_IFSOCK)
		return ("s");
	return ("-");
}

char			*init_time(t_stat *cstat)
{
	size_t		index;
	char		*tmp_time;
	char		*new_time;

	index = 4;
	new_time = (char *)ft_memalloc(sizeof(char) << 4);
	tmp_time = ctime(&(cstat->st_mtime));
	while (index < 16)
	{
		new_time[index - 4] = tmp_time[index];
		++index;
	}
	new_time[index] = '\0';
	return (new_time);
}

void			display_rights(t_stat *cstat)
{
	write(1, iforest(cstat->st_mode), 1);
	write(1, (cstat->st_mode & S_IRUSR) ? "r" : "-", 1);
	write(1, (cstat->st_mode & S_IWUSR) ? "w" : "-", 1);
	write(1, (cstat->st_mode & S_IXUSR) ? "x" : "-", 1);
	write(1, (cstat->st_mode & S_IRGRP) ? "r" : "-", 1);
	write(1, (cstat->st_mode & S_IWGRP) ? "w" : "-", 1);
	write(1, (cstat->st_mode & S_IXGRP) ? "x" : "-", 1);
	write(1, (cstat->st_mode & S_IROTH) ? "r" : "-", 1);
	write(1, (cstat->st_mode & S_IWOTH) ? "w" : "-", 1);
	write(1, (cstat->st_mode & S_IXOTH) ? "x" : "-", 1);
}
