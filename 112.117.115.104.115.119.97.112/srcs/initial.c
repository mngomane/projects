/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 22:58:04 by mngomane          #+#    #+#             */
/*   Updated: 2013/12/29 23:23:26 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_varinit(t_var *v, t_list *tab1, t_list *tab2)
{
	tab1->len++;
	tab2->len--;
	v->tmp1 = (int *)malloc(sizeof(int) * (tab1->len));
	v->tmp2 = (int *)malloc(sizeof(int) * (tab2->len));
	v->tmp3 = tab2->value[0];
	v->i = 0;
}

void	ft_varinit2(t_list *l_a, t_list *l_b, size_t *i, int *ac)
{
	(void)l_b;
	l_b = NULL;
	l_a->value = (int *)malloc(sizeof(int) * (size_t)(*ac - 1));
	l_a->len = (size_t)(*ac - 1);
	*i = 1;
}

void	ft_filltab(t_list *l_a, size_t *i, char **av)
{
	while (*i < l_a->len + 1)
	{
		l_a->value[*i - 1] = ft_atoi(av[*i]);
		++(*i);
	}
	*i = 0;
}
