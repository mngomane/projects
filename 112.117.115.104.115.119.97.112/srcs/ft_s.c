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

void	ft_s(t_stack *list)
{
	int	tmp;

	if (list != NULL)
	{
		tmp = (list->value)[1];
		(list->value)[1] = (list->value)[0];
		(list->value)[0] = tmp;
	}
}

void	ft_ss(t_stack *list1, t_stack *list2)
{
	ft_s(list1);
	ft_s(list2);
}
