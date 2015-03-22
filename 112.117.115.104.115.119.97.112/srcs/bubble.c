/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 02:20:31 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/29 23:31:20 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_into_b(t_stack *l_a, t_stack *l_b)
{
	size_t		i;
	size_t		j;
	int			value;

	i = 0;
	j = 0;
	value = (l_a->value)[0];
	while (i < l_a->size)
	{
		if ((l_a->value)[i] < value)
		{
			value = (l_a->value)[i];
			j = i;
		}
		++i;
	}
	i = 0;
	while (i++ < j)
	{
		rotate_elem(l_a);
		write(1, "ra ", 3);
	}
	push_elem(l_b, l_a);
	write(1, "pb ", 3);
}

void			bub_swap(t_stack *l_a, t_stack *l_b)
{
	while (l_a->size > 0)
		push_into_b(l_a, l_b);
	while (l_b->size > 1)
	{
		push_elem(l_a, l_b);
		write(1, "pa ", 3);
	}
	push_elem(l_a, l_b);
	write(1, "pa\n", 3);
}
