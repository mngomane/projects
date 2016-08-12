/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 07:27:43 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/19 07:27:43 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		unlink_node(void *ptr)
{
	t_area		prev;
	t_area		next;

	next = NEXT_PTR(ptr);
	next = NBR_TO_PTR(ft_btos(&next));
	prev = PREV_PTR(ptr);
	prev = NBR_TO_PTR(ft_btos(&prev));
	if (prev)
	{
		prev += AREA_NEXT;
		if (next)
		{
			next += AREA_SIZE;
			ft_stob(&prev, ft_btos(&next));
			next -= AREA_SIZE;
		}
		else
			ft_stob(&prev, 0);
		prev -= AREA_NEXT;
	}
}

void			free(void *ptr)
{
	t_area		tmp;
	size_t		len;

	len = 0;
	tmp = (t_area)((char *)ptr - 1);
	if (ptr != (void *)0)
	{
		if (*tmp == 'L')
		{
			unlink_node(ptr);
			tmp = SIZE_PTR(ptr);
			len = ft_btos(&tmp);
			if (munmap((char *)ptr - 35, len) == -1)
				ft_puts("munmap failed: free.c");
		}
		else if ((*tmp == 'T' || *tmp == 'S') && *(tmp - 1) == 'B')
		{
			ft_puts("Free: T or S");
			tmp -= 1;
			*tmp = 'F';
		}
		else
			ft_puts("*** error : pointer being freed was not allocated");
	}
}
