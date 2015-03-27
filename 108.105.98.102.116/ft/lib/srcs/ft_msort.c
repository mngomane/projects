/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 23:35:17 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/27 23:35:17 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static void		merge(int *tab, size_t size, size_t mid)
{
	int			*tmp;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = mid;
	k = 0;
	tmp = malloc(size * sizeof(int));
	while (k < size)
		tmp[k++] = ((j != size && (i == mid || tab[j] < tab[i])) ?
			tab[j++] : tab[i++]);
	i = size;
	while (--i)
		tab[i] = tmp[i];
	tab[0] = tmp[0];
	free(tmp);
}

void			ft_msort(int *tab, size_t size)
{
	size_t		mid;

	if (size < 2)
		return;
	mid = size >> 1;
	ft_msort(tab, mid);
	ft_msort(tab + mid, size - mid);
	merge(tab, size, mid);
}
