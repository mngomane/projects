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

ssize_t		ft_printnwstr_fd(wchar_t const *s, char *opt, int fd)
{
	ssize_t		ret;
	ssize_t		len;
	size_t		size;

	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	ret = 0;
	if (s == (void *)0)
	{
		if (size > 6)
			return (ft_putnchar_fd(opt[PF_PADC], (size - 6), fd) +
				write(fd, "(null)", 6));
		return (ft_putstr_fd("(null)", fd));
	}
	len = (ssize_t)size;
	subtract_wc(s, &len);
	if (len > 0)
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	while (*s)
		ret += ft_putwchar_fd(*(s++), fd);
	return (ret);
}
