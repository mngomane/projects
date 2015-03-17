/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucs2_to_utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 21:08:55 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/17 21:08:55 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	seven_bits(int ucs2, u_char *utf8)
{
	utf8[0] = (u_char)ucs2;
	utf8[1] = '\0';
	return (1);
}

static int	eleven_bits(int ucs2, u_char *utf8)
{
	utf8[0] = (u_char)((ucs2 >> 6) | 0xc0);
	utf8[1] = (ucs2 & 0x3f) | 0x80;
	utf8[2] = '\0';
	return (2);
}

static int	sixteen_bits(int ucs2, u_char *utf8)
{
	if (ucs2 >= 0xd800 && ucs2 <= 0xdfff)
		return (-1);
	utf8[0] = (u_char)((ucs2 >> 12) | 0xe0);
	utf8[1] = ((ucs2 >> 6) & 0x3f) | 0x80;
	utf8[2] = ((ucs2) & 0x3f) | 0x80;
	utf8[3] = '\0';
	return (3);
}

static int	twenty_one_bits(int ucs2, u_char *utf8)
{
	utf8[0] = (u_char)(0xf0 | (ucs2 >> 18));
	utf8[1] = 0x80 | ((ucs2 >> 12) & 0x3f);
	utf8[2] = 0x80 | ((ucs2 >> 6) & 0x3f);
	utf8[3] = 0x80 | ((ucs2 & 0x3f));
	utf8[4] = '\0';
	return (4);
}

int			ft_ucs2_to_utf8(int ucs2, u_char *utf8)
{
	if (ucs2 < 0x80)
		return (seven_bits(ucs2, utf8));
	if (ucs2 >= 0x80 && ucs2 < 0x800)
		return (eleven_bits(ucs2, utf8));
	if (ucs2 >= 0x800 && ucs2 < 0xffff)
		return (sixteen_bits(ucs2, utf8));
	if (ucs2 >= 0x10000 && ucs2 < 0x10ffff)
		return (twenty_one_bits(ucs2, utf8));
	return (-1);
}
