/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:39:24 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 23:39:24 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include <time.h>
#include "ft_ls.h"

static char		*ft_time_init(t_stat *cstat)
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

static void		ft_display_rights(t_stat *cstat)
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

static void		putendlong(t_list *lst)
{
	t_stat		*cstat;
	char		*tmp;

	cstat = LVALUE(t_file *, lst)->stat;
	tmp = ft_time_init(cstat);
	ft_display_rights(cstat);
	ft_printf("  %2ld", cstat->st_nlink);
	ft_printf(" %s", getpwuid(cstat->st_uid)->pw_name);
	ft_printf(" %s", getgrgid(cstat->st_gid)->gr_name);
	ft_printf(" %5ld", cstat->st_size);
	ft_printf(" %s", tmp);
	ft_printf(" %s\n", (char *)(LVALUE(t_file *, lst)->name));
	free(tmp);
}

void			printl_lst(t_list *lst, u_char flags)
{
	while (lst)
	{
		if (((char *)LVALUE(t_file *, lst)->name)[0] != '.' ||
			(((char *)LVALUE(t_file *, lst)->name)[0] == '.' &&
			F_ALL(flags)))
			putendlong(lst);
		lst = lst->next;
	}
}

void			print_lst(t_list *lst, u_char flags)
{
	while (lst)
	{
		if (LVALUE(t_file *, lst)->stat != (void *)0)
		{
			if (((char *)LVALUE(t_file *, lst)->name)[0] != '.' ||
				(((char *)LVALUE(t_file *, lst)->name)[0] == '.' &&
				F_ALL(flags)))
				ft_putendl((char *)(LVALUE(t_file *, lst)->name));
		}
		lst = lst->next;
	}
}
