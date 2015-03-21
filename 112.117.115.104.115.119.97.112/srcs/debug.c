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
		ft_printf("%d ", (list.value)[i++]);
	if (i < list.size)
		ft_putnbr((list.value)[i]);
	write(1, "\n", 1);
}

void			display_stacks(t_stack l_a, t_stack l_b)
{
	ft_printf("%s\n%s", I_NB, I_FSS);
	display_the_stack(l_a);
	ft_putstr(I_SSS);
	display_the_stack(l_b);
}
