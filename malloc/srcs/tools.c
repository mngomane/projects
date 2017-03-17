/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 06:54:41 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/19 06:54:41 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	ft_putnbr_off_t(off_t n, pid_t pid)
{
	off_t	decim;
	char	c;

	decim = 1;
	while ((n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		c = (n / decim) % 10 + '0';
		write(pid, &c, 1);
		decim /= 10;
	}
}

void		ft_putnbr_hex(uintptr_t p)
{
	uintptr_t	hex;
	char		c;

	hex = 1;
	write(1, "0x", 2);
	while ((p / hex) > 16)
		hex *= 16;
	while (hex > 0)
	{
		c = (p / hex) % 16;
		c += ((c < 10) ? '0' : 'a' - 10);
		write(1, &c, 1);
		hex /= 16;
	}
}

char		*find_available_space(t_area *address, size_t size, char needle)
{
	char	*tmp;
	size_t	index;

	tmp = (char *)0;
	index = 0;
	while ((index < 100 * size) && (*address)[index + 33] != 0)
		index += size;
	if (index < 100 * size)
	{
		(*address)[index + 32] = CHAR_CAST((index / size));
		(*address)[index + 33] = CHAR_CAST('B');
		(*address)[index + 34] = CHAR_CAST(needle);
		tmp = (char *)*address + index + 35;
	}
	if (index == 99 * size)
		(*address)[AREA_STATE] = 'F';
	return (tmp);
}

t_area		find_mblock(t_area *address, char needle)
{
	t_area	tmp;
	t_area	save;
	t_area	next;

	tmp = (t_area)0;
	save = *address;
	next = (t_area)0;
	while (*address && tmp == (t_area)0)
	{
		next = *address + AREA_NEXT;
		next = NBR_TO_PTR(ft_btos(&next));
		if (((intptr_t)(*address)[AREA_TYPE] == needle) &&
			((intptr_t)(*address)[AREA_STATE] == 'A'))
		{
			tmp = *address;
			if (needle == 'L')
				(*address)[AREA_STATE] = 'F';
		}
		*address = NBR_TO_PTR(next);
	}
	*address = save;
	return (tmp);
}

// void		show_alloc_mem(void)
// {
// 	t_area	save;
// 	t_area	next;
// 	size_t	size;

// 	save = g_area;
// 	size = 0;
// 	while (g_area)
// 	{
// 		if (*(g_area + AREA_TYPE) == 'T')
// 			write(1, "\nTINY  : ", 9);
// 		else if (*(g_area + AREA_TYPE) == 'S')
// 			write(1, "\nSMALL : ", 9);
// 		else
// 			write(1, "\nLARGE : ", 9);
// 		ft_putnbr_hex((uintptr_t)g_area);
// 		next = NEXT(g_area);
// 		next = (next ? NBR_TO_PTR(ft_btos(&next)) : (t_area)0);
// 		g_area += AREA_SIZE;
// 		size += ft_btos(&g_area);
// 		g_area = next;
// 	}
// 	g_area = save;
// 	write(1, "\nTotal : ", 9);
// 	ft_putnbr_off_t((off_t)size, 1);
// 	ft_puts(" octets");
// }
