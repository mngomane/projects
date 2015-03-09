/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 16:27:35 by mngomane          #+#    #+#             */
/*   Updated: 2014/05/04 17:13:14 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_select.h"

void		display_sel(t_term *term, t_arg **arg)
{
	t_arg	*save;

	save = *arg;
	while (*arg)
	{
		if (term->p[Y] == (*arg)->pos)
			tputs(tgetstr("us", &(term->area)), 1, ft_putchar);
		if ((*arg)->sel)
			tputs(tgetstr("so", &(term->area)), 1, ft_putchar);
		write(1, (*arg)->aname, ft_strlen((*arg)->aname));
		write(1, "\n", 1);
		if ((*arg)->sel)
			tputs(tgetstr("se", &(term->area)), 1, ft_putchar);
		if (term->p[Y] == (*arg)->pos)
			tputs(tgetstr("ue", &(term->area)), 1, ft_putchar);
		*arg = (*arg)->next;
	}
	*arg = save;
}

void		ed_sel(t_term *term, t_arg **arg, t_var *var, t_read *inp)
{
	if ((var->buff_len == 3) && (inp->buff[2] == UP))
		term->p[Y] = (term->p[Y] == 0 ? (var->narg - 1) : term->p[Y] - 1);
	if ((var->buff_len == 3) && (inp->buff[2] == DOWN))
		term->p[Y] = (term->p[Y] == (var->narg - 1) ? 0 : term->p[Y] + 1);
	if (inp->buff[0] == SPACE)
	{
		while (*arg)
		{
			if ((*arg)->pos == (size_t)term->p[Y])
				(*arg)->sel = ((*arg)->sel ? 0 : 1);
			*arg = (*arg)->next;
		}
		*arg = var->save;
		term->p[Y] = (term->p[Y] == (var->narg - 1) ? 0 : term->p[Y] + 1);
	}
}

void		del_sel(t_term *term, t_arg **arg, t_var *var, t_read *inp)
{
	if (inp->buff[0] == BKSP || (var->buff_len == 4 && inp->buff[3] == DEL))
	{
		if (*arg)
		{
			if ((*arg)->next)
			{
				del_arg(term, arg, var, term->p[Y]);
				if (var->narg > 1)
					--(var->narg);
			}
			else
				*arg = NULL;
		}
	}
}

int			q_sel(t_term *term, t_arg **arg, t_var *var, t_read *inp)
{
	if ((var->buff_len == 1) && (inp->buff[0] == ESC))
	{
		tputs(tgetstr("cl", &(term->area)), 1, ft_putchar);
		if (tcsetattr(0, 0, &(term->new_config)) < 0)
		{
			write(2, "Error with tcsetattr (in main.c)\n", 33);
			return (-1);
		}
		tputs(tgetstr("ve", &(term->area)), 1, ft_putchar);
		return (42);
	}
	if ((var->buff_len == 1) && (inp->buff[0] == RETURN))
	{
		if (!sub_return(term, arg, var))
		{
			write(2, "Error with tcsetattr (in main.c)\n", 33);
			return (-1);
		}
		return (42);
	}
	return (0);
}
