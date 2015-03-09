/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 08:49:33 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/19 08:49:33 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			ft_stob(t_area *address, const size_t size)
{
	int8_t	byte;

	byte = 0;
	while (byte < 8)
	{
		(*address)[byte] = (((size_t)size >> (byte * 8)) & 0xff);
		++byte;
	}
}

size_t			ft_btos(t_area *address)
{
	size_t	value;
	int8_t	byte;

	value = 0;
	byte = 0;
	while (byte < 8)
	{
		value += ((size_t)(*address)[byte] << (byte * 8));
		++byte;
	}
	return (value);
}

size_t			ft_get_right_size(size_t size)
{
	size_t	page_size;
	size_t	tmp;

	page_size = (size_t)getpagesize();
	tmp = 0;
	while (size > tmp)
		tmp += page_size;
	return (tmp);
}

static void		attach_node(t_area *add, t_area tmp, char needle, size_t size)
{
	if (needle == 'T')
		tmp = (t_area)mmap(0, ft_get_right_size(100 * N_SIZE + 332),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	else if (needle == 'S')
		tmp = (t_area)mmap(0, ft_get_right_size(100 * M_SIZE + 332),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	else
		tmp = (t_area)mmap(0, ft_get_right_size(size + 35),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	tmp[NODE_TYPE] = 'L';
	tmp[AREA_TYPE] = (u_char)needle;
	tmp[AREA_STATE] = 'A';
	tmp[AREA_FSTATE] = 'U';
	if (*add)
	{
		tmp += AREA_PREV;
		ft_stob(&tmp, (uintptr_t)*add);
		tmp -= AREA_PREV;
		*add += AREA_NEXT;
		ft_stob(add, (uintptr_t)tmp);
		*add -= AREA_NEXT;
	}
	else
		*add = tmp;
}

void			add_node(t_area *address, char needle, size_t size)
{
	t_area	save;
	t_area	next;
	t_area	tmp;

	tmp = (t_area)0;
	save = *address;
	next = NEXT(*address);
	next = (next ? NBR_TO_PTR(ft_btos(&next)) : (t_area)0);
	while (*address && next)
	{
		*address = next;
		next = *address + AREA_NEXT;
		next = NBR_TO_PTR(ft_btos(&next));
	}
	attach_node(address, tmp, needle, size);
	*address = save;
}
