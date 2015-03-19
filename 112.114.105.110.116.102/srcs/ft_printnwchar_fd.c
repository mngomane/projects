/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnwchar_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 01:21:10 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 01:21:10 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnwchar_fd(wchar_t const c, int p, size_t z, int d)
{
	u_char	utf8[5];
	ssize_t	l;

	if (c == 0)
	{
		if (!z)
			return (1);
		return (ft_putnchar_fd(p, z, d));
	}
	ft_bzero(utf8, 5 * sizeof(u_char));
	ft_wc_to_utf8(c, utf8);
	l = (ssize_t)z - (ssize_t)ft_strlen((char *)utf8);
	if (l > 0)
	{
		l = ft_putnchar_fd(p, (size_t)l, d) + ft_putstr_fd((char *)utf8, d);
		return (l);
	}
	return (ft_putstr_fd((char *)utf8, d));
}
