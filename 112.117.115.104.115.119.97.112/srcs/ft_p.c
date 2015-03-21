/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 05:25:06 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/29 23:03:54 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		set_value(t_stack *lst1, t_stack *lst2, int *tmp1, int *tmp2)
{
	free(lst1->value);
	free(lst2->value);
	lst1->value = tmp1;
	lst2->value = tmp2;
}

void			ft_p(t_stack *list1, t_stack *list2)
{
	int			*tmp1;
	int			*tmp2;
	size_t		index;

	index = 0;
	if (list2->size > 0)
	{
		tmp1 = (int *)malloc(sizeof(int) * ++list1->size);
		tmp2 = (int *)malloc(sizeof(int) * --list2->size);
		while (index < list2->size)
		{
			tmp2[index] = (list2->value)[index + 1];
			++index;
		}
		tmp1[0] = (list2->value)[0];
		index = 0;
		while (++index < list1->size)
			tmp1[index] = (list1->value)[index - 1];
		set_value(list1, list2, tmp1, tmp2);
	}
}
