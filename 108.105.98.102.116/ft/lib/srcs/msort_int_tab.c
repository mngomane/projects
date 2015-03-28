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

static void		merge(int *tab, size_t size, size_t mid, int (*cmp)(int, int))
{
	int			*tmp;
	size_t		offset;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = mid;
	k = 0;
	offset = (uintptr_t)(&tab + 1) - (uintptr_t)&tab;
	tmp = (int *)malloc(size * offset);
	while (k < size)
		tmp[k++] = ((j != size && (i == mid || cmp(tab[j], tab[i]))) ?
			tab[j++] : tab[i++]);
	i = size;
	while (--i)
		tab[i] = tmp[i];
	tab[0] = tmp[0];
	free(tmp);
}

void			msort_int_tab(int *tab, size_t size, int (*cmp)(int, int))
{
	size_t		mid;

	if (size < 2)
		return ;
	mid = size >> 1;
	msort_int_tab(tab, mid, cmp);
	msort_int_tab(tab + mid, size - mid, cmp);
	merge(tab, size, mid, cmp);
}
