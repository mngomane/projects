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

void	ft_p(t_list *tab1, t_list *tab2)
{
	t_var	v;

	if (tab2->len > 0)
	{
		ft_varinit(&v, tab1, tab2);
		while (v.i < tab2->len)
		{
			v.tmp2[v.i] = tab2->value[v.i + 1];
			++v.i;
		}
		v.tmp1[0] = v.tmp3;
		v.i = 1;
		while (v.i < tab1->len)
		{
			v.tmp1[v.i] = tab1->value[v.i - 1];
			++v.i;
		}
		free(tab1->value);
		free(tab2->value);
		tab1->value = v.tmp1;
		tab2->value = v.tmp2;
	}
}
