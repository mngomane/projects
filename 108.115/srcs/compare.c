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
	time_t		sec1;
	time_t		sec2;
	long		nsec1;
	long		nsec2;

	sec1 = LSTAT(lst1)->st_mtimespec.tv_sec;
	sec2 = LSTAT(lst2)->st_mtimespec.tv_sec;
	nsec1 = LSTAT(lst1)->st_mtimespec.tv_nsec;
	nsec2 = LSTAT(lst2)->st_mtimespec.tv_nsec;
	if (sec1 == sec2)
		return (nsec1 < nsec2);
	return (sec1 < sec2);
}

int			time_cmp(t_list *lst1, t_list *lst2)
{
	time_t		sec1;
	time_t		sec2;
	long		nsec1;
	long		nsec2;

	sec1 = LSTAT(lst1)->st_mtimespec.tv_sec;
	sec2 = LSTAT(lst2)->st_mtimespec.tv_sec;
	nsec1 = LSTAT(lst1)->st_mtimespec.tv_nsec;
	nsec2 = LSTAT(lst2)->st_mtimespec.tv_nsec;
	if (sec1 == sec2)
		return (nsec1 > nsec2);
	return (sec1 > sec2);
}

int			reverse_cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp(LNAME(lst1), LNAME(lst2)) > 0);
}

int			lexical_cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp(LNAME(lst1), LNAME(lst2)) < 0);
}
