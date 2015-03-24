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

#include "ft_printf.h"

static ssize_t	subtract_wc(wchar_t const *s, ssize_t *len)
{
	wchar_t		*tmp;
	u_char		utf8[5];

	tmp = (wchar_t *)s;
	while (*tmp)
	{
		if (ft_strlen((char *)utf8) == 1)
			return (0);
		ft_bzero(utf8, 5 * sizeof(u_char));
		ft_wc_to_utf8(*(tmp++), utf8);
		*len -= ft_strlen((char *)utf8);
	}
	return (1);
}

static size_t	get_size(char *opt)
{
	size_t		size;

	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	return (size);
}

static ssize_t	ret_null(char *opt, int fd)
{
	ssize_t		ret;

	ret = 0;
	if (get_size(opt) > 6)
		ret += ft_putnchar_fd(opt[PF_PADC], (get_size(opt) - 6), fd);
	return (ret + write(fd, "(null)", 6));
}

static ssize_t	fct1(wchar_t const *s, char *opt, ssize_t tmp, int fd)
{
	u_char		utf8[5];
	ssize_t		ret[2];
	int			len;

	ft_bzero(ret, 2 * sizeof(ssize_t));
	if (ft_mtoz(opt + PF_PREC) >= ft_mtoz(opt + PF_PERIOD))
	{
		if (tmp)
			ret[0] += ft_putnchar_fd(opt[PF_PADC], ft_mtoz(opt + PF_PREC) -
				ft_mtoz(opt + PF_PERIOD) + ft_mtoz(opt + PF_PERIOD) % 3, fd);
		else
			ret[0] += ft_putnchar_fd(opt[PF_PADC], ft_mtoz(opt + PF_PREC) -
				ft_mtoz(opt + PF_PERIOD), fd);
	}
	len = ft_wc_to_utf8(*s, utf8);
	while (*s && ret[1] + len <= (ssize_t)ft_mtoz(opt + PF_PERIOD))
	{
		tmp = ft_putwchar_fd(*(s++), fd);
		ret[0] += tmp;
		ret[1] += tmp;
		ft_bzero(utf8, 5 * sizeof(u_char));
		len = ft_wc_to_utf8(*s, utf8);
	}
	return (ret[0]);
}

ssize_t			ft_printnwstr_fd(wchar_t const *s, char *opt, int fd)
{
	ssize_t		ret;
	ssize_t		len;
	ssize_t		tmp;

	if (s == (void *)0)
		return (ret_null(opt, fd));
	tmp = 0;
	ret = 0;
	len = (ssize_t)get_size(opt);
	tmp = subtract_wc(s, &len);
	if (len > 0 && tmp)
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	if (opt[PF_DOT] && ft_mtoz(opt + PF_PERIOD) < (size_t)len)
		ret += fct1(s, opt, tmp, fd);
	else
		while (*s)
			ret += ft_putwchar_fd(*(s++), fd);
	return (ret);
}
