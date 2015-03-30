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
#include <unistd.h>
#include "ft_ls.h"




#include <stdio.h>


int			putendlong(t_list *lst)
{
	t_stat			*cstat;
	char			*tmp;
	ssize_t			ret;

	ret = 0;
	cstat = LVALUE(t_file *, lst)->stat;
	tmp = init_time(cstat);
	ret += display_rights(cstat);
	ret += ft_printf("  %2ld", cstat->st_nlink);
	getpwuid(cstat->st_uid);
	getgrgid(cstat->st_gid);
	/*ret += ft_printf(" %s", getpwuid(cstat->st_uid)->pw_name);
	ret += ft_printf(" %s", getgrgid(cstat->st_gid)->gr_name);*/
	if (S_ISCHR(cstat->st_mode) || S_ISBLK(cstat->st_mode))
		ret += ft_printf("  %5u, %3u", major(cstat->st_rdev),
							minor(cstat->st_rdev));
	else
		ret += ft_printf("  %5ld", cstat->st_size);
	ret += ft_printf(" %s", tmp);
	ret += ft_printf(" %s", (char *)(LVALUE(t_file *, lst)->name));
	free(tmp);
	tmp = (void *)0;
	if (S_ISLNK(cstat->st_mode))
	{
		tmp = ft_memalloc(sizeof(char) << 9);
		readlink((char *)(LVALUE(t_file *, lst)->name), tmp, 1 << 9);
		/*readlink((char *)(LVALUE(t_file *, lst)->name), tmp, 1 << 9);*/
		ret += ft_printf(" -> %s", tmp);
		free(tmp);
	}
	ret += write(1, "\n", 1);
	return ((int)ret);
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
			{
				if (F_LONG(flags))
					putendlong(lst);
				else
					ft_putendl((char *)(LVALUE(t_file *, lst)->name));
			}
		}
		lst = lst->next;
	}
}
