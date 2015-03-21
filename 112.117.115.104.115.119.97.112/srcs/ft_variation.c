/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 17:54:39 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/29 22:47:27 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_abs(int *n)
{
	*n = ((*n < 0) ? -1 : 1);
}

int		variations(t_stack *list)
{
	int		sign;
	int		i;
	off_t	cmp;

	i = 1;
	if (list->size == 0)
		return (0);
	cmp = (off_t)(list->value)[i] - (off_t)(list->value)[i - 1];
	sign = (cmp >= 0 ? 1 : -1);
	while (sign * cmp >= 0 && i < (int)list->size)
	{
		++i;
		cmp = (off_t)(list->value)[i] - (off_t)(list->value)[i - 1];
	}
	return (sign * i);
}
