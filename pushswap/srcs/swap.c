/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 04:52:48 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/27 00:36:00 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elem(t_stack *list)
{
	int	tmp;

	if (list != (void *)0 && list->size > 1)
	{
		tmp = (list->value)[1];
		(list->value)[1] = (list->value)[0];
		(list->value)[0] = tmp;
	}
}

void	swap_all(t_stack *list1, t_stack *list2)
{
	swap_elem(list1);
	swap_elem(list2);
}
