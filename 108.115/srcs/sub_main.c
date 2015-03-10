/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 17:28:25 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 19:50:18 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_ls.h"

void			fill_arg_list(t_list **arg, int ac, int j, char **av)
{
	int		i;

	i = ac - 2;
	while (i > j - 1)
	{
		*arg = add_link(*arg, av[i]);
		--i;
	}
}

void			fill_list(t_list **arg, t_opt **op, int ac, char **av)
{
	int			i;

	i = 2;
	if (i < ac)
	{
		while (av[i][0] == '-' && i < ac - 1)
		{
			*op = add_opt(*op, av[i]);
			++i;
		}
		if (av[i][0] == '-')
		{
			*op = add_opt(*op, av[i]);
			++i;
		}
		if (i < ac)
		{
			(*arg)->dir->fname = av[ac - 1];
			if (i < ac - 1)
				fill_arg_list(arg, ac, i, av);
		}
	}
}

int				init_main(t_list **arg, t_opt **op, int ac)
{
	if ((*arg = (t_list *)malloc(sizeof(t_list))) == NULL)
	{
		write(2, "malloc in main failled (main.c)\n", 32);
		return (0);
	}
	if (((*arg)->dir = (t_var *)malloc(sizeof(t_var))) == NULL)
	{
		write(2, "malloc in main failled (main.c)\n", 32);
		return (0);
	}
	if ((*op = (t_opt *)malloc(sizeof(t_opt))) == NULL)
	{
		write(2, "malloc in main failled (main.c)\n", 32);
		return (0);
	}
	(*arg)->dir->len = 0;
	(*arg)->dir->ac = ac;
	(*op)->onbr = 0;
	return (1);
}

void			sub_main(t_list *arg, t_opt *op, int ac)
{
	static void	(*l_fct[3])(t_list *) = {ft_larg, sub_nolfile, sub_nolfile2};
	static void	(*a_fct[3])(t_list *) = {ft_arg, sub_noafile, sub_noafile2};
	static void	(*e_fct[3])(t_list *) = {ft_arg, sub_nofile, sub_nofile2};

	if (op->oname == NULL)
		no_file(arg, e_fct, ac);
	else
	{
		if (!valid_op(&op))
			whatelse(op->oname);
		else
		{
			if (ft_strcmp(op->oname, "-l") == 0)
				no_lfile(arg, l_fct, ac);
			else if (ft_strcmp(op->oname, "-a") == 0)
				no_afile(arg, a_fct, ac);
			else
				whatelse(op->oname);
		}
	}
}

void			body_main(t_list *arg, t_opt *op, int ac, char **av)
{
	int			i;

	i = ac - 2;
	if (ac > 1)
	{
		if (av[1][0] == '-')
			op->oname = av[1];
		else
			arg->dir->fname = av[ac - 1];
		if (arg->dir->fname == NULL)
			fill_list(&arg, &op, ac, av);
		else
		{
			while (i > 0)
			{
				arg = add_link(arg, av[i]);
				--i;
			}
		}
		sub_main(arg, op, ac);
	}
	else
		ft_noarg(arg);
}
