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

void	ft_r(t_stack *list)
{
	int		tmp;
	size_t	i;

	i = 0;
	/*tmp = tab->value[0];*/
	tmp = (list->value)[0];
	while (i < list->size - 1)
	{
		/*tab->value[i] = tab->value[i + 1];*/
		(list->value)[i] = (list->value)[i + 1];
		++i;
	}
	/*tab->value[i] = tmp;*/
	(list->value)[i] = tmp;
}

void	ft_rr(t_stack *list)
{
	int		tmp;
	size_t	i;

	tmp = 0;
	if (list->size > 0)
	{
		i = list->size;
		/*tmp = tab->value[i - 1];*/
		tmp = (list->value)[i - 1];
		while (i > 0)
		{
			/*tab->value[i] = tab->value[i - 1];*/
			(list->value)[i] = (list->value)[i - 1];
			--i;
		}
		(list->value)[0] = tmp;
	}
}
