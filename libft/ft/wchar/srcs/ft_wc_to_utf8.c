/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc_to_utf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 21:08:55 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/17 21:08:55 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

static int	seven_bits(wchar_t const wc, u_char *utf8)
{
	utf8[0] = (u_char)wc;
	utf8[1] = '\0';
	return (1);
}

static int	eleven_bits(wchar_t const wc, u_char *utf8)
{
	utf8[0] = (u_char)((wc >> 6) | 0xc0);
	utf8[1] = (wc & 0x3f) | 0x80;
	utf8[2] = '\0';
	return (2);
}

static int	sixteen_bits(wchar_t const wc, u_char *utf8)
{
	if (wc >= 0xd800 && wc <= 0xdfff)
		return (-1);
	utf8[0] = (u_char)((wc >> 12) | 0xe0);
	utf8[1] = ((wc >> 6) & 0x3f) | 0x80;
	utf8[2] = ((wc) & 0x3f) | 0x80;
	utf8[3] = '\0';
	return (3);
}

static int	twenty_one_bits(wchar_t const wc, u_char *utf8)
{
	utf8[0] = (u_char)(0xf0 | (wc >> 18));
	utf8[1] = 0x80 | ((wc >> 12) & 0x3f);
	utf8[2] = 0x80 | ((wc >> 6) & 0x3f);
	utf8[3] = 0x80 | ((wc & 0x3f));
	utf8[4] = '\0';
	return (4);
}

int			ft_wc_to_utf8(wchar_t const wc, u_char *utf8)
{
	if (wc < 0x80)
		return (seven_bits(wc, utf8));
	if (wc >= 0x80 && wc < 0x800)
		return (eleven_bits(wc, utf8));
	if (wc >= 0x800 && wc < 0xffff)
		return (sixteen_bits(wc, utf8));
	if (wc >= 0x10000 && wc < 0x10ffff)
		return (twenty_one_bits(wc, utf8));
	return (-1);
}
