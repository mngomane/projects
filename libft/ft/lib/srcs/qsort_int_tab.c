/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_int_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 00:45:10 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/28 00:45:10 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void			qsort_int_tab(int *tab, size_t size, int (*cmp)(int, int))
{
	size_t		index[2];
	int			pivot;
	int			tmp[2];

	if (size < 2)
		return ;
	I = 0;
	tmp[1] = 1;
	J = size - 1;
	pivot = tab[size >> 1];
	while ((tmp[1] = (I >= J ? 0 : 42)))
	{
		while (cmp(tab[I], pivot))
			I++;
		while (cmp(pivot, tab[J]))
			J--;
		if (I < J)
		{
			tmp[0] = tab[index[0]];
			tab[I++] = tab[J];
			tab[J--] = tmp[0];
		}
	}
	qsort_int_tab(tab, I, cmp);
	qsort_int_tab(tab + I, size - I, cmp);
}
