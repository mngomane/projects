/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:25:24 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 23:25:24 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			rtime_cmp(t_list *lst1, t_list *lst2)
{
	if (LVALUE(t_file *, lst1)->stat->st_mtimespec.tv_sec ==
		LVALUE(t_file *, lst2)->stat->st_mtimespec.tv_sec)
		return (LVALUE(t_file *, lst1)->stat->st_mtimespec.tv_nsec <
				LVALUE(t_file *, lst2)->stat->st_mtimespec.tv_nsec );
	return (LVALUE(t_file *, lst1)->stat->st_mtimespec.tv_sec <
				LVALUE(t_file *, lst2)->stat->st_mtimespec.tv_sec );
}

int			time_cmp(t_list *lst1, t_list *lst2)
{
	if (LVALUE(t_file *, lst1)->stat->st_mtimespec.tv_sec ==
		LVALUE(t_file *, lst2)->stat->st_mtimespec.tv_sec)
		return (LVALUE(t_file *, lst1)->stat->st_mtimespec.tv_nsec >
				LVALUE(t_file *, lst2)->stat->st_mtimespec.tv_nsec );
	return (LVALUE(t_file *, lst1)->stat->st_mtimespec.tv_sec >
				LVALUE(t_file *, lst2)->stat->st_mtimespec.tv_sec );
}

int			reverse_cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp((char *)(LVALUE(t_file *, lst1)->name),
			(char *)(LVALUE(t_file *, lst2)->name)) > 0);
}

int			lexical_cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp((char *)(LVALUE(t_file *, lst1)->name),
			(char *)(LVALUE(t_file *, lst2)->name)) < 0);
}
