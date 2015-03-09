/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 02:20:31 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/29 23:31:20 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap1(t_list *l_a, t_list *l_b, size_t *i, t_index *tmp)
{
	while (l_a->len > 0)
	{
		tmp->val = l_a->value[0];
		tmp->ind = 0;
		while (*i < l_a->len)
		{
			if (l_a->value[*i] < tmp->val)
			{
				tmp->val = l_a->value[*i];
				tmp->ind = *i;
			}
			++(*i);
		}
		*i = 0;
		while (*i < tmp->ind)
		{
			ft_r(l_a);
			write(1, "ra ", 3);
			++(*i);
		}
		*i = 0;
		ft_p(l_b, l_a);
		write(1, "pb ", 3);
	}
}

void	ft_swap2(t_list *l_a, t_list *l_b)
{
	while (l_b->len > 1)
	{
		ft_p(l_a, l_b);
		write(1, "pa ", 3);
	}
	ft_p(l_a, l_b);
	write(1, "pa\n", 3);
}
