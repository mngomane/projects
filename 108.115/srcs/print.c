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

void			putendlong(t_list *lst)
{
	t_stat		*cstat;
	char		*tmp;

	cstat = LVALUE(t_file *, lst)->stat;
	tmp = init_time(cstat);
	display_rights(cstat);
	ft_printf("  %2ld", cstat->st_nlink);
	ft_printf(" %s", getpwuid(cstat->st_uid)->pw_name);
	ft_printf(" %s", getgrgid(cstat->st_gid)->gr_name);
	ft_printf(" %5ld", cstat->st_size);
	ft_printf(" %s", tmp);
	ft_printf(" %s\n", (char *)(LVALUE(t_file *, lst)->name));
	free(tmp);
}

/*void			printl_lst(t_list *lst, u_char flags)
{
	while (lst)
	{
		if (((char *)LVALUE(t_file *, lst)->name)[0] != '.' ||
			(((char *)LVALUE(t_file *, lst)->name)[0] == '.' &&
			F_ALL(flags)))
			putendlong(lst);
		lst = lst->next;
	}
}*/

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
