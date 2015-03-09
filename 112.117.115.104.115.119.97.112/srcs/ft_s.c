/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 04:52:48 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/27 00:36:00 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_list *tab)
{
	int	tmp;

	if (tab != NULL)
	{
		tmp = tab->value[1];
		tab->value[1] = tab->value[0];
		tab->value[0] = tmp;
	}
}

void	ft_ss(t_list *tab1, t_list *tab2)
{
	ft_s(tab1);
	ft_s(tab2);
}
