/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 00:01:36 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/27 00:37:13 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r(t_list *tab)
{
	int		tmp;
	size_t	i;

	i = 0;
	tmp = tab->value[0];
	while (i < tab->len - 1)
	{
		tab->value[i] = tab->value[i + 1];
		++i;
	}
	tab->value[i] = tmp;
}

void	ft_rr(t_list *tab)
{
	int		tmp;
	size_t	i;

	if (tab->len > 0)
	{
		i = tab->len;
		tmp = tab->value[i - 1];
		while (i > 0)
		{
			tab->value[i] = tab->value[i - 1];
			--i;
		}
		tab->value[0] = tmp;
	}
}
