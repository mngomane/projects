/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:41:56 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 23:41:56 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		dir_part(t_list **lst, u_char flags, u_char check)
{
	t_list		*save;

	check |= M_FIRST;
	save = *lst;
	while (*lst)
	{
		if (LSTAT(*lst) != (void *)0 && (LSTAT(*lst)->st_mode & S_IFDIR))
		{
			((check & M_FIRST) ? check ^= M_FIRST : ft_putendl(""));
			if (check & M_MOREDIR || ((check & M_ONEDIR) && (check & M_FILE)))
				ft_printf("%s:\n", LNAME(*lst));
			fdisplay(0, (void *)0, LNAME(*lst), flags);
		}
		*lst = (*lst)->next;
	}
	*lst = save;
	ft_lstdel(lst, del_lst);
}

static t_list	*file_part(t_list *lst, u_char flags, u_char *check)
{
	t_list		*save;

	save = lst;
	while (lst)
	{
		if (LSTAT(lst) != (void *)0 && !(LSTAT(lst)->st_mode & S_IFDIR))
		{
			if (LNAME(lst)[0] != '.' || (LNAME(lst)[0] == '.' && F_ALL(flags)))
			{
				*check |= M_FILE;
				(F_LONG(flags) ? putendlong(lst) : ft_putendl(LNAME(lst)));
			}
		}
		else if (LSTAT(lst) != (void *)0)
			*check |= ((*check & M_ONEDIR) ? M_MOREDIR : M_ONEDIR);
		lst = lst->next;
	}
	lst = save;
	((*check & M_FILE) && (*check & M_ONEDIR) ? ft_putendl("") : 0);
	return (lst);
}

static int		(*iforest(u_char flags))(t_list *, t_list *)
{
	if (F_REVERSE(flags) && F_TIME(flags))
		return (rtime_cmp);
	else if (F_REVERSE(flags))
		return (reverse_cmp);
	else if (F_TIME(flags))
		return (time_cmp);
	return (lexical_cmp);
}

static t_list	*finit(int ac, char **av, u_char flags)
{
	t_list		*lst;
	int			(*cmp)(t_list *, t_list *);

	lst = (void *)0;
	cmp = iforest(flags);
	sort_lstadd((void *)0, (void *)0, (void *)0);
	while (ac--)
		sort_lstadd(&lst, ft_lstnew(new_file("", av[ac], flags),
									sizeof(t_file)), cmp);
	return (lst);
}

int				fdisplay(int ac, char **av, char *name, u_char flags)
{
	t_list		*lst;
	u_char		check;
	int			(*cmp)(t_list *, t_list *);

	cmp = iforest(flags);
	if (ac < 1)
	{
		if ((lst = ilst(name, cmp, flags)) == (void *)0)
			return (-1);
		print_lst(lst, flags);
		ft_lstdel(&lst, del_lst);
	}
	else
	{
		check = 0;
		lst = finit(ac, av, flags);
		lst = file_part(lst, flags, &check);
		dir_part(&lst, flags, check);
	}
	return (0);
}
