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

#include "ft_ls.h"

int				putendlong(t_list *lst)
{
	char		*tmp;
	ssize_t		ret;

	ret = 0;
	ret += display_rights(LSTAT(lst));
	ret += ft_printf("%4ld", LSTAT(lst)->st_nlink);
	ret += ft_printf(" %s", LPASS(lst)->pw_name);
	ret += ft_printf(" %s", LGROUP(lst)->gr_name);
	if (S_ISCHR(LSTAT(lst)->st_mode) || S_ISBLK(LSTAT(lst)->st_mode))
		ret += ft_printf("%7u, %3u", major(LSTAT(lst)->st_rdev),
							minor(LSTAT(lst)->st_rdev));
	else
		ret += ft_printf("%7ld", LSTAT(lst)->st_size);
	tmp = init_time(LSTAT(lst));
	ret += ft_printf(" %s", tmp);
	ret += ft_printf(" %s", LNAME(lst));
	if (S_ISLNK(LSTAT(lst)->st_mode))
		ret += ft_printf(" -> %s", LLINK(lst));
	ret += write(1, "\n", 1);
	return ((int)ret);
}

void			print_lst(t_list *lst, u_char flags, quad_t block)
{
	u_char		check;

	check = 0;
	while (lst)
	{
		if (LSTAT(lst) != (void *)0)
		{
			if (LNAME(lst)[0] != '.' || (LNAME(lst)[0] == '.' && F_ALL(flags)))
			{
				if (F_LONG(flags))
				{
					(!(check & 0x01) ? ft_printf("total %lld\n", block) : 0);
					check |= 0x01;
					putendlong(lst);
				}
				else
					ft_putendl(LNAME(lst));
			}
		}
		lst = lst->next;
	}
}
