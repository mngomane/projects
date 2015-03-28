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
	size_t		i;
	size_t		j;
	int			pivot;
	int			tmp;

	if (size < 2)
		return ;
	i = 0;
	j = size - 1;
	pivot = tab[size >> 1];
	while (42)
	{
		while (cmp(tab[i], pivot))
			i++;
		while (cmp(pivot, tab[j]))
			j--;
		if (i >= j)
			break ;
		tmp = tab[i];
		tab[i++] = tab[j];
		tab[j--] = tmp;
	}
	qsort_int_tab(tab, i, cmp);
	qsort_int_tab(tab + i, size - i, cmp);
}
