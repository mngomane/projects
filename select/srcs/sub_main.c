/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 23:02:56 by mngomane          #+#    #+#             */
/*   Updated: 2014/05/04 20:35:36 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <term.h>
#include "ft_select.h"

static int	ft_cldisplay(t_term *term, t_arg **arg, t_var *var, t_read *inp)
{
	char		*ret;

	ret = NULL;
	tputs(tgetstr("cl", &(term->area)), 1, ft_putchar);
	display_sel(term, arg);
	var->i = 0;
	while (var->i < 42)
	{
		inp->buff[var->i] = '\0';
		++(var->i);
	}
	ret = tgoto(tgetstr("cm", &(term->area)), (int)term->p[X], (int)term->p[Y]);
	tputs(ret, 1, ft_putchar);
	tputs(tgetstr("ue", &(term->area)), 1, ft_putchar);
	if ((inp->ret = read(0, inp->buff, 42)) < 0)
		return (0);
	var->buff_len = ft_strlen(inp->buff);
	return (1);
}

int			sub_return(t_term *term, t_arg **arg, t_var *var)
{
	tputs(tgetstr("cl", &(term->area)), 1, ft_putchar);
	if (tcsetattr(0, 0, &(term->new_config)) < 0)
		return (0);
	tputs(tgetstr("ve", &(term->area)), 1, ft_putchar);
	while (*arg != NULL && !var->first)
	{
		if ((*arg)->sel)
		{
			write(1, (*arg)->aname, ft_strlen((*arg)->aname));
			var->first = 1;
		}
		*arg = (*arg)->next;
	}
	while (*arg)
	{
		if ((*arg)->sel)
		{
			write(1, " ", 1);
			write(1, (*arg)->aname, ft_strlen((*arg)->aname));
		}
		*arg = (*arg)->next;
	}
	write(1, "\n", 1);
	return (1);
}

int			sub_main(t_term *term, t_arg **arg, t_var *var)
{
	t_read	inp;

	while (42)
	{
		if (!(*arg))
		{
			tputs(tgetstr("cl", &(term->area)), 1, ft_putchar);
			if (tcsetattr(0, 0, &(term->new_config)) < 0)
				return (0);
			tputs(tgetstr("ve", &(term->area)), 1, ft_putchar);
			return (1);
		}
		if (!ft_cldisplay(term, arg, var, &inp))
			return (0);
		ed_sel(term, arg, var, &inp);
		del_sel(term, arg, var, &inp);
		if ((var->quit = q_sel(term, arg, var, &inp)) != 0)
		{
			if (var->quit == -1)
				return (0);
			if (var->quit == 42)
				return (1);
		}
	}
}
