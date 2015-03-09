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

int		ft_var(t_list tab)
{
	int		sign;
	int		i;
	off_t	overflow_control;

	i = 1;
	if (tab.len == 0)
		return (0);
	overflow_control = (off_t)tab.value[i] - (off_t)tab.value[i - 1];
	sign = (overflow_control >= 0 ? 1 : -1);
	while (sign * overflow_control >= 0 && i < (int)tab.len)
	{
		++i;
		overflow_control = (off_t)tab.value[i] - (off_t)tab.value[i - 1];
	}
	return (sign * i);
}
