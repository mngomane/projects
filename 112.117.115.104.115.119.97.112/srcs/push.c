/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 05:25:06 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/29 23:03:54 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		set_value(t_stack *dest, t_stack *origin, int *tmp1, int *tmp2)
{
	free(dest->value);
	free(origin->value);
	dest->value = tmp1;
	origin->value = tmp2;
}

void			push_elem(t_stack *dest, t_stack *origin)
{
	int			*tmp1;
	int			*tmp2;
	size_t		index;

	index = 0;
	if (origin && origin->size > 0)
	{
		tmp1 = (int *)malloc(sizeof(int) * ++dest->size);
		tmp2 = (int *)malloc(sizeof(int) * --origin->size);
		while (index < origin->size)
		{
			tmp2[index] = (origin->value)[index + 1];
			++index;
		}
		tmp1[0] = (origin->value)[0];
		index = 0;
		while (++index < dest->size)
			tmp1[index] = (dest->value)[index - 1];
		set_value(dest, origin, tmp1, tmp2);
	}
}
