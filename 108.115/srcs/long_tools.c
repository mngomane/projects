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

static char		*iforest(mode_t mode)
{
	if (S_ISLNK(mode))
		return ("l");
	if (S_ISCHR(mode))
		return ("c");
	if (S_ISFIFO(mode))
		return ("P");
	if (S_ISDIR(mode))
		return ("d");
	if (S_ISBLK(mode))
		return ("b");
	if (S_ISSOCK(mode))
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

ssize_t			display_rights(t_stat *cstat)
{
	ssize_t		ret;

	ret = 0;
	ret += write(1, iforest(cstat->st_mode), 1);
	ret += write(1, (cstat->st_mode & S_IRUSR) ? "r" : "-", 1);
	ret += write(1, (cstat->st_mode & S_IWUSR) ? "w" : "-", 1);



	/*ret += write(1, (cstat->st_mode & S_IXUSR) ? "x" : "-", 1);*/
	if (!(cstat->st_mode & S_IXUSR) && (cstat->st_mode & S_ISUID))
		ret += write(1, "S", 1);
	else if ((cstat->st_mode & S_IXUSR) && (cstat->st_mode & S_ISUID))
		ret += write(1, "s", 1);
	else if ((cstat->st_mode & S_IXUSR))
		ret += write(1, "x", 1);
	else
		ret += write(1, "-", 1);



	ret += write(1, (cstat->st_mode & S_IRGRP) ? "r" : "-", 1);
	ret += write(1, (cstat->st_mode & S_IWGRP) ? "w" : "-", 1);



	/*ret += write(1, (cstat->st_mode & S_IXGRP) ? "x" : "-", 1);*/
	if (!(cstat->st_mode & S_IXUSR) && (cstat->st_mode & S_ISGID))
		ret += write(1, "S", 1);
	else if ((cstat->st_mode & S_IXUSR) && (cstat->st_mode & S_ISGID))
		ret += write(1, "s", 1);
	else if ((cstat->st_mode & S_IXUSR))
		ret += write(1, "x", 1);
	else
		ret += write(1, "-", 1);


	ret += write(1, (cstat->st_mode & S_IROTH) ? "r" : "-", 1);
	ret += write(1, (cstat->st_mode & S_IWOTH) ? "w" : "-", 1);



	/*ret += write(1, (cstat->st_mode & S_IXOTH) ? "x" : "-", 1);*/
	if (!(cstat->st_mode & S_IXUSR) && (cstat->st_mode & S_ISVTX))
		ret += write(1, "T", 1);
	else if ((cstat->st_mode & S_IXUSR) && (cstat->st_mode & S_ISVTX))
		ret += write(1, "t", 1);
	else if ((cstat->st_mode & S_IXUSR))
		ret += write(1, "x", 1);
	else
		ret += write(1, "-", 1);



	return (ret);
}
