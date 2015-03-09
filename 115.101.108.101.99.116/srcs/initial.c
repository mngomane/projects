/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 16:15:59 by mngomane          #+#    #+#             */
/*   Updated: 2014/05/04 16:47:07 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "ft_select.h"

int			term_init(t_term *term, char **ep)
{
	if (*ep != NULL)
		term->type = getenv("TERM");
	else
		term->type = "xterm-256color";
	term->ret = tgetent(term->buff, term->type);
	if (tcgetattr(0, &(term->old_config)) < 0)
		return (0);
	term->new_config = term->old_config;
	term->new_config.c_lflag &= (unsigned long)(~(ECHO | ICANON));
	term->new_config.c_cc[VTIME] = 0;
	term->new_config.c_cc[VMIN] = 1;
	if (tcsetattr(0, 0, &(term->new_config)) < 0)
		return (0);
	if ((term->area = (char *)malloc(sizeof(char) * 42)) == NULL)
		return (0);
	term->p[X] = 0;
	term->p[Y] = 0;
	tputs(tgetstr("vi", &(term->area)), 1, ft_putchar);
	return (1);
}

int			sub_init(t_arg **arg, t_var *var, int ac, char **av)
{
	var->first = 0;
	var->narg = (size_t)ac - 1;
	var->i = var->narg - 1;
	if ((*arg = (t_arg *)malloc(sizeof(t_arg))) == NULL)
		return (0);
	(*arg)->aname = av[ac - 1];
	if (ac > 1)
		(*arg)->pos = (size_t)ac - 2;
	else
		(*arg)->pos = 0;
	(*arg)->sel = 0;
	(*arg)->next = NULL;
	while (var->i > 1)
	{
		*arg = add_arg(arg, av[var->i], (*arg)->pos);
		--(var->i);
	}
	if (var->i == 1)
		*arg = add_arg(arg, av[var->i], (*arg)->pos);
	var->save = *arg;
	var->i = 0;
	return (1);
}
