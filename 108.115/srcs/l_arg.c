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
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "ft_ls.h"

static void	ft_time_init(t_list *arg)
{
	arg->dir->i = 4;
	arg->dir->new_time = (char *)malloc(sizeof(char) * 13);
	arg->dir->tmp_time = ctime(&(arg->dir->filestat.st_mtime));
	while (arg->dir->i < 16)
	{
		arg->dir->new_time[arg->dir->i - 4] = arg->dir->tmp_time[arg->dir->i];
		++(arg->dir->i);
	}
	arg->dir->new_time[arg->dir->i] = '\0';
}

static void	ft_display_rights(t_list *arg)
{
	write(1, (S_ISDIR(arg->dir->filestat.st_mode)) ? "d" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IRUSR) ? "r" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IWUSR) ? "w" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IXUSR) ? "x" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IRGRP) ? "r" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IWGRP) ? "w" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IXGRP) ? "x" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IROTH) ? "r" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IWOTH) ? "w" : "-", 1);
	write(1, (arg->dir->filestat.st_mode & S_IXOTH) ? "x" : "-", 1);
}

static void	ft_display(char *str)
{
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
}

void		ft_larg(t_list *arg)
{
	ft_time_init(arg);
	ft_display_rights(arg);
	write(1, "  ", 2);
	ft_putnbr_off_t(arg->dir->filestat.st_nlink);
	ft_display(getpwuid(arg->dir->filestat.st_uid)->pw_name);
	ft_display(getgrgid(arg->dir->filestat.st_gid)->gr_name);
	write(1, " ", 1);
	ft_putnbr_off_t(arg->dir->filestat.st_size);
	arg->dir->size = arg->dir->filestat.st_size;
	ft_display(arg->dir->new_time);
	ft_display(arg->dir->fname);
	write(1, "\n", 1);
	free(arg->dir->new_time);
}
