/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 16:10:56 by mngomane          #+#    #+#             */
/*   Updated: 2014/05/04 20:38:18 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_select.h"

int			main(int ac, char **av, char **ep)
{
	t_term	term;
	t_var	var;
	t_arg	*arg;

	if (ac == 1)
		return (0);
	if (!sub_init(&arg, &var, ac, av))
	{
		write(2, "Error with sub_init call (main.c)\n", 34);
		tputs(tgetstr("ve", &(term.area)), 1, ft_putchar);
		return (-1);
	}
	if (!term_init(&term, ep))
	{
		write(2, "Error with term_init call (main.c)\n", 35);
		tputs(tgetstr("ve", &(term.area)), 1, ft_putchar);
		return (-1);
	}
	if (!sub_main(&term, &arg, &var))
	{
		write(2, "Error with sub_main call (main.c)\n", 34);
		tputs(tgetstr("ve", &(term.area)), 1, ft_putchar);
		return (-1);
	}
	return (0);
}
