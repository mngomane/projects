/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 07:28:47 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/19 07:28:47 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc(void *ptr, size_t size)
{
	char	*tmp;
	int		n;
	int		m;

	n = N_SIZE;
	m = M_SIZE;
	tmp = (char *)0;
	if (ptr == (void *)0)
		tmp = (char *)malloc(size);
	else if (((n - (int)size) >= 0 && *((char *)ptr - BACK_TYPE) == 'T') ||
		((m - (int)size) >= 0 && *((char *)ptr - BACK_TYPE) == 'S'))
		tmp = ptr;
	else
	{
		tmp = (char *)malloc(size);
		tmp = (char *)ft_memcpy(tmp, ptr, size);
		free((char *)ptr);
	}
	return ((void *)tmp);
}
