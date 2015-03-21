/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 23:59:48 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/09 23:59:48 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		display_the_stack(t_stack list)
{
	size_t		i;

	i = 0;
	while (i + 1 < list.size)
	{
		ft_putnbr((list.value)[i]);
		write(1, " ", 1);
		++i;
	}
	if (i < list.size)
		ft_putnbr((list.value)[i]);
	write(1, "\n", 1);
}

void			display_stacks(t_stack l_a, t_stack l_b)
{
	/*ft_puts("NB: The first number displayed is on the top of the stack !!!");*/
	ft_putendl("NB: The first number displayed is on the top of the stack !!!");
	write(1, "first stack state: ", 19);
	display_the_stack(l_a);
	write(1, "second stack state: ", 20);
	display_the_stack(l_b);
}
