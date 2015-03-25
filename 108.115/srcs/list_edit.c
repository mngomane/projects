/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 17:33:42 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 17:55:08 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_var	*tmpdir(char *name, int ac)
{
	t_var		*tmp;

	if ((tmp = (t_var *)malloc(sizeof(t_var))) != (void *)0)
	{
		tmp->fname = name;
		tmp->ac = ac;
	}
	else
		ft_puterr(FAILED_ALLOC);
	return (tmp);
}

t_list			*add_link(t_list *arg, char *name)
{
	t_list		*tmp;

	if (LVALUE(t_var *, arg)->fname == (void *)0)
	{
		LVALUE(t_var *, arg)->fname = name;
		return (arg);
	}
	if ((tmp = (t_list *)malloc(sizeof(t_list))) == (void *)0)
		ft_puterr(FAILED_ALLOC);
	else
	{
		tmp->content = tmpdir(name, LVALUE(t_var *, arg)->ac);
		tmp->next = arg;
	}
	return (tmp);
}

t_opt			*add_opt(t_opt *op, char *name)
{
	t_opt		*tmp;

	if ((tmp = (t_opt *)malloc(sizeof(t_opt))) != (void *)0)
	{
		tmp->oname = name;
		tmp->onbr += op->onbr;
		tmp->next = op;
	}
	else
		ft_puterr(FAILED_ALLOC);
	return (tmp);
}

void			free_link(t_list **arg)
{
	t_list		*save;

	save = *arg;
	while (*arg)
	{
		free(LVALUE(t_var *, (*arg)));
		*arg = (*arg)->next;
	}
	*arg = save;
	while (*arg)
	{
		free(*arg);
		*arg = (*arg)->next;
	}
	*arg = save;
}

void			free_opt(t_opt **op)
{
	t_opt		*save;

	save = *op;
	while (*op)
	{
		free(*op);
		*op = (*op)->next;
	}
	*op = save;
}
