/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msort_int_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 23:35:17 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/27 23:35:17 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static void		merge(int *tab, size_t size, size_t med, int (*cmp)(int, int))
{
	int			*tmp;
	size_t		offset;
	size_t		index[3];

	I = 0;
	J = med;
	K = 0;
	offset = (uintptr_t)(&tab + 1) - (uintptr_t)&tab;
	tmp = (int *)malloc(size * offset);
	while (K < size)
		tmp[K++] = ((J != size && (I == med || cmp(tab[J], tab[I]))) ?
			tab[J++] : tab[I++]);
	I = size;
	while (--I)
		tab[I] = tmp[I];
	tab[0] = tmp[0];
	free(tmp);
}

void			msort_int_tab(int *tab, size_t size, int (*cmp)(int, int))
{
	size_t		med;

	if (size < 2)
		return ;
	med = size >> 1;
	msort_int_tab(tab, med, cmp);
	msort_int_tab(tab + med, size - med, cmp);
	merge(tab, size, med, cmp);
}
