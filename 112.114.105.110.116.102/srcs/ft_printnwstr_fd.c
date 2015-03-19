/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnwstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 01:41:52 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 01:41:52 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	subtract_wc(wchar_t const *s, ssize_t *len)
{
	wchar_t		*tmp;
	u_char		utf8[5];

	tmp = (wchar_t *)s;
	while (*tmp)
	{
		ft_bzero(utf8, 5 * sizeof(u_char));
		ft_wc_to_utf8(*(tmp++), utf8);
		*len -= ft_strlen((char *)utf8);
	}
}

ssize_t		ft_printnwstr_fd(wchar_t const *s, char *o, size_t z, int fd)
{
	ssize_t		ret;
	ssize_t		len;

	ret = 0;
	if (s == (void *)0)
	{
		if (z > 6)
			return (ft_putnchar_fd(o[PF_PADC], (z - 6), fd) + write(fd, "(null)", 6));
		return (ft_putstr_fd("(null)", fd));
	}
	len = (ssize_t)z;
	subtract_wc(s, &len);
	if (len > 0)
		ret += ft_putnchar_fd(o[PF_PADC], (size_t)len, fd);
	while (*s)
		ret += ft_putwchar_fd(*(s++), fd);
	return (ret);
}
