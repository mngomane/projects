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

ssize_t		ft_printnwstr_fd(wchar_t const *s, char *opt, int fd)
{
	ssize_t		ret;
	ssize_t		len;
	size_t		size;

	ssize_t		index;
	ssize_t		tmp;
	u_char		utf8[5];

	index = 0;
	tmp = 0;

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
	tmp = subtract_wc(s, &len);
	if (len > 0 && tmp)
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	/*else if (len > 0)
		ret += ft_putnchar_fd(opt[PF_PADC], ft_mtoz(opt + PF_PERIOD), fd);*/
	/*if (opt[PF_DOT] && ft_mtoz(opt + PF_PERIOD) < ft_strlen(s))
		len = (ssize_t)size - (ssize_t)ft_mtoz(opt + PF_PERIOD);
	else
		len = (ssize_t)size - (ssize_t)ft_strlen(s);*/
	if (opt[PF_DOT] && ft_mtoz(opt + PF_PERIOD) < (size_t)len)
	{
		if (ft_mtoz(opt + PF_PREC) >= ft_mtoz(opt + PF_PERIOD))
		{
			/*if (ft_mtoz(opt + PF_PERIOD))*/
			if (tmp)
				ret += ft_putnchar_fd(opt[PF_PADC], ft_mtoz(opt + PF_PREC) -
					ft_mtoz(opt + PF_PERIOD) + ft_mtoz(opt + PF_PERIOD) % 3, fd);
			else
				ret += ft_putnchar_fd(opt[PF_PADC], ft_mtoz(opt + PF_PREC) -
					ft_mtoz(opt + PF_PERIOD), fd);
			/*else
				ret += ft_putnchar_fd(opt[PF_PADC], ft_mtoz(opt + PF_PREC), fd);*/
		}
		ft_wc_to_utf8(*s, utf8);
		while (*s && index + (ssize_t)ft_strlen((char *)utf8) <=
				(ssize_t)ft_mtoz(opt + PF_PERIOD))
		{
			tmp = ft_putwchar_fd(*(s++), fd);
			ret += tmp;
			index += tmp;
			ft_bzero(utf8, 5 * sizeof(u_char));
			ft_wc_to_utf8(*s, utf8);
		}
	}
	else
		while (s[index])
			ret += ft_putwchar_fd(*(s++), fd);
	/*while (*s)
	{
		ret += ft_putwchar_fd(*(s++), fd);
	}*/
	return (ret);
}
