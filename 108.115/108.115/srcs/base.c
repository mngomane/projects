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
		if (LVALUE(t_file *, *lst)->stat != (void *)0 &&
			(LVALUE(t_file *, *lst)->stat->st_mode & S_IFDIR))
		{
			((check & M_FIRST) ? check ^= M_FIRST : ft_putendl(""));
			if (check & M_MOREDIR || ((check & M_ONEDIR) && (check & M_FILE)))
				ft_printf("%s:\n", (char *)(LVALUE(t_file *, *lst)->name));
			fdisplay(0, (void *)0, (char *)(LVALUE(t_file *, *lst)->name),
				flags);
		}
		*lst = (*lst)->next;
	}
	*lst = save;
	ft_lstdel(lst, del_lst);
}

static t_list	*file_part(t_list *lst, u_char flags, u_char *check)
{
	t_list		*save;

	(void)flags;
	save = lst;
	while (lst)
	{
		if (LVALUE(t_file *, lst)->stat != (void *)0 &&
			!(LVALUE(t_file *, lst)->stat->st_mode & S_IFDIR))
		{
			if (((char *)LVALUE(t_file *, lst)->name)[0] != '.' ||
				(((char *)LVALUE(t_file *, lst)->name)[0] == '.' &&
				F_ALL(flags)))
			{
				*check |= M_FILE;
				ft_putendl((char *)(LVALUE(t_file *, lst)->name));
			}
		}
		else if (LVALUE(t_file *, lst)->stat != (void *)0)
			*check |= ((*check & M_ONEDIR) ? M_MOREDIR : M_ONEDIR);
		lst = lst->next;
	}
	lst = save;
	((*check & M_FILE) && (*check & M_ONEDIR) ? ft_putendl("") : 0);
	return (lst);
}

/*static t_lut	*init_lookup(void)
{
	t_lut		*lookup;
	int			tab[8];

	tab[0] = 0x01;
	tab[1] = 0x02;
	tab[2] = 0x04;
	tab[3] = 0x04;
	lookup = (t_lut *)ft_memalloc(sizeof(t_lut) << 3);
	lookup[0].key = ""
	return (lookup);
}*/

static t_list	*finit(int ac, char **av, u_char flags)
{
	t_list		*lst;
	int			(*cmp)(t_list *, t_list *);

	(void)ac, (void)av, (void)flags;
	lst = (void *)0;
	if (F_REVERSE(flags))
		cmp = reverse_cmp;
	else
		cmp = lexical_cmp;
	sort_lstadd((void *)0, (void *)0, (void *)0);
	while (ac--)
		sort_lstadd(&lst, ft_lstnew(new_file("", av[ac]), sizeof(t_file)),
			cmp);
	return (lst);
}

int				fdisplay(int ac, char **av, char *name, u_char flags)
{
	t_list		*lst;
	u_char		check;
	int			(*cmp)(t_list *, t_list *);

	if (F_REVERSE(flags))
		cmp = reverse_cmp;
	else
		cmp = lexical_cmp;
	if (ac < 1)
	{
		if ((lst = ilst(name, cmp)) == (void *)0)
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
