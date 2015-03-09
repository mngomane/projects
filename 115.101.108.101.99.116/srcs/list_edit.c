/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 16:30:11 by mngomane          #+#    #+#             */
/*   Updated: 2014/05/04 16:13:40 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

t_arg			*add_arg(t_arg **arg, char *aname, size_t pos)
{
	t_arg	*tmp;

	if ((tmp = (t_arg *)malloc(sizeof(t_arg))) != NULL)
	{
		tmp->aname = aname;
		if (pos != 0)
		{
			tmp->pos = pos - 1;
			tmp->sel = 0;
			tmp->next = (*arg);
		}
		else
		{
			free (tmp);
			return (*arg);
		}
	}
	else
		write(2, "malloc in add_arg failed\n", 25);
	return (tmp);
}

static void		sub_del(t_term *term, t_arg **arg, t_arg **prev, t_var *var)
{
	if (!((*arg)->next))
		--(term->p[Y]);
	if (*prev)
	{
		(*prev)->next = (*arg)->next;
		*prev = (*prev)->next;
		while (*prev)
		{
			--(*prev)->pos;
			*prev = (*prev)->next;
		}
	}
	else
	{
		*arg = (*arg)->next;
		var->save = *arg;
		while (*arg)
		{
			--(*arg)->pos;
			*arg = (*arg)->next;
		}
	}
	*arg = var->save;
}

void			del_arg(t_term *term, t_arg **arg, t_var *var, size_t pos)
{
	t_arg	*tmp;
	t_arg	*prev;

	var->save = *arg;
	prev = NULL;
	tmp = NULL;
	if (*arg)
	{
		while ((*arg)->pos != pos && (*arg)->next != NULL)
		{
			prev = *arg;
			*arg = (*arg)->next;
		}
		if ((*arg)->pos == pos)
		{
			tmp = *arg;
			sub_del(term, arg, &prev, var);
			free(tmp);
		}
	}
}

void			free_arg(t_arg **arg)
{
	while (*arg)
	{
		free(*arg);
		*arg = (*arg)->next;
	}
}
