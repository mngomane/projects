/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 07:28:14 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/19 07:28:14 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_area			g_area = (void *)0;

static void		init_malloc(void)
{
	g_area = (t_area)mmap(0, ft_get_right_size(100 * N_SIZE + 332),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	g_area[NODE_TYPE] = 'R';
	g_area[AREA_TYPE] = 'T';
	g_area[AREA_STATE] = 'A';
	g_area[AREA_FSTATE] = 'U';
	g_area += AREA_SIZE;
	ft_stob(&g_area, ft_get_right_size(N_SIZE * 100 + 332));
	g_area -= AREA_SIZE;
	g_area += AREA_PREV;
	ft_stob(&g_area, 0);
	g_area -= AREA_PREV;
	g_area += AREA_NEXT;
	ft_stob(&g_area, 0);
	g_area -= AREA_NEXT;
}

static void		*tiny_malloc(void)
{
	t_area	area;
	char	*tmp;

	area = (void *)0;
	tmp = (void *)0;
	area = find_mblock(&g_area, 'T');
	if (!area)
	{
		add_node(&g_area, 'T', 1);
		area = find_mblock(&g_area, 'T');
	}
	area += AREA_SIZE;
	ft_stob(&area, ft_get_right_size(100 * N_SIZE + 332));
	area -= AREA_SIZE;
	tmp = find_available_space(&area, N_SIZE, 'T');
	return ((void *)tmp);
}

static void		*small_malloc(void)
{
	t_area	area;
	char	*tmp;

	area = (void *)0;
	tmp = (void *)0;
	area = find_mblock(&g_area, 'S');
	if (!area)
	{
		add_node(&g_area, 'S', 1);
		area = find_mblock(&g_area, 'S');
	}
	area += AREA_SIZE;
	ft_stob(&area, ft_get_right_size(100 * M_SIZE + 332));
	area -= AREA_SIZE;
	tmp = find_available_space(&area, M_SIZE, 'S');
	return ((void *)tmp);
}

static void		*large_malloc(size_t size)
{
	t_area	area;
	char	*tmp;

	area = (void *)0;
	tmp = (void *)0;
	add_node(&g_area, 'L', size);
	area = find_mblock(&g_area, 'L');
	area += AREA_SIZE;
	ft_stob(&area, ft_get_right_size(size + 35));
	area -= AREA_SIZE;
	area[DATA_START] = 0;
	area[DATA_START + 1] = 'B';
	area[DATA_START + 2] = 'L';
	tmp = (char *)area + 35;
	return ((void *)tmp);
}

void			*malloc(size_t size)
{
	char	*tmp;
	size_t	n;
	size_t	m;

	n = N_SIZE;
	m = M_SIZE;
	tmp = (void *)0;
	if (g_area == (void *)0)
		init_malloc();
	if (size <= n)
		tmp = (char *)tiny_malloc();
	else if (size <= m)
		tmp = (char *)small_malloc();
	else
		tmp = (char *)large_malloc(size);
	return ((void *)tmp);
}
