/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 00:45:10 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/28 00:45:10 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void			ft_qsort(int *tab, size_t size)
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
		while (tab[i] < pivot)
			i++;
		while (pivot < tab[j])
			j--;
		if (i >= j)
			break ;
		tmp = tab[i];
		tab[i++] = tab[j];
		tab[j--] = tmp;
	}
	ft_qsort(tab, i);
	ft_qsort(tab + i, size - i);
}
