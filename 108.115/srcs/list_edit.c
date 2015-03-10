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

#include <stdlib.h>
#include <unistd.h>
#include "ft_ls.h"

static t_var	*tmpdir(char *name, int ac)
{
	t_var	*tmp;

	if ((tmp = (t_var *)malloc(sizeof(t_var))) != NULL)
	{
		tmp->fname = name;
		tmp->ac = ac;
	}
	else
		write(2, "malloc in tmpdir failed (main.c)\n", 33);
	return (tmp);
}

t_list			*add_link(t_list *arg, char *name)
{
	t_list	*tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		tmp->dir = tmpdir(name, arg->dir->ac);
		tmp->next = arg;
	}
	else
		write(2, "malloc in add_link failed (main.c)\n", 35);
	return (tmp);
}

t_opt			*add_opt(t_opt *op, char *name)
{
	t_opt	*tmp;

	if ((tmp = (t_opt *)malloc(sizeof(t_opt))) != NULL)
	{
		tmp->oname = name;
		tmp->onbr += op->onbr;
		tmp->next = op;
	}
	else
		write(2, "malloc in add_link failed (main.c)\n", 35);
	return (tmp);
}

void			free_link(t_list **arg)
{
	t_list	*save;

	save = *arg;
	while (*arg)
	{
		free((*arg)->dir);
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
	t_opt	*save;

	save = *op;
	while (*op)
	{
		free(*op);
		*op = (*op)->next;
	}
	*op = save;
}
