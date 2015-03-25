/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 14:31:16 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 20:11:03 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include <time.h>
#include "ft_ls.h"

static void		ft_time_init(t_list *arg)
{
	size_t		index;

	index = 4;
	LVALUE(t_var *, arg)->new_time = (char *)malloc(sizeof(char) * 13);
	LVALUE(t_var *, arg)->tmp_time =
		ctime(&(LVALUE(t_var *, arg)->filestat.st_mtime));
	while (index < 16)
	{
		LVALUE(t_var *, arg)->new_time[index - 4] =
			LVALUE(t_var *, arg)->tmp_time[index];
		++index;
	}
	LVALUE(t_var *, arg)->new_time[index] = '\0';
}

static void		ft_display_rights(t_list *arg)
{
	write(1, (S_ISDIR(LVALUE(t_var *, arg)->filestat.st_mode)) ? "d" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IRUSR) ? "r" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IWUSR) ? "w" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IXUSR) ? "x" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IRGRP) ? "r" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IWGRP) ? "w" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IXGRP) ? "x" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IROTH) ? "r" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IWOTH) ? "w" : "-", 1);
	write(1, (LVALUE(t_var *, arg)->filestat.st_mode & S_IXOTH) ? "x" : "-", 1);
}

void			ft_larg(t_list *arg)
{
	ft_time_init(arg);
	ft_display_rights(arg);
	ft_printf("  %ld", LVALUE(t_var *, arg)->filestat.st_nlink);
	ft_printf(" %s", getpwuid(LVALUE(t_var *, arg)->filestat.st_uid)->pw_name);
	ft_printf(" %s", getgrgid(LVALUE(t_var *, arg)->filestat.st_gid)->gr_name);
	ft_printf(" %ld", LVALUE(t_var *, arg)->filestat.st_size);
	LVALUE(t_var *, arg)->size = LVALUE(t_var *, arg)->filestat.st_size;
	ft_printf(" %s", LVALUE(t_var *, arg)->new_time);
	ft_printf(" %s\n", LVALUE(t_var *, arg)->fname);
	free(LVALUE(t_var *, arg)->new_time);
}
