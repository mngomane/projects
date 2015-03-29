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

void			print_lst(t_list *lst, u_char flags)
{
	while (lst)
	{
		if (LVALUE(t_file *, lst)->stat != (void *)0)
		{
			if (((char *)LVALUE(t_file *, lst)->name)[0] != '.' ||
				(((char *)LVALUE(t_file *, lst)->name)[0] == '.' &&
				F_ALL(flags)))
				/*ft_putendl((char *)(LVALUE(t_file *, lst)->path));*/
				ft_putendl((char *)(LVALUE(t_file *, lst)->name));
		}
		lst = lst->next;
	}
}
