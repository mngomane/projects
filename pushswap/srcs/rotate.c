/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 00:01:36 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/27 00:37:13 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_elem(t_stack *list)
{
	int		tmp;
	size_t	i;

	i = 0;
	tmp = (list->value)[0];
	while (i < list->size - 1)
	{
		(list->value)[i] = (list->value)[i + 1];
		++i;
	}
	(list->value)[i] = tmp;
}

void	rotate_all(t_stack *list1, t_stack *list2)
{
	rotate_elem(list1);
	rotate_elem(list2);
}

void	reverse_rotate_elem(t_stack *list)
{
	int		tmp;
	size_t	i;

	tmp = 0;
	if (list->size > 0)
	{
		i = list->size - 1;
		tmp = (list->value)[i];
		while (i > 0)
		{
			(list->value)[i] = (list->value)[i - 1];
			--i;
		}
		(list->value)[0] = tmp;
	}
}

void	reverse_rotate_all(t_stack *list1, t_stack *list2)
{
	reverse_rotate_elem(list1);
	reverse_rotate_elem(list2);
}
