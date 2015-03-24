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

#include "ft_printf.h"

ssize_t			ft_printnwchar_fd(wchar_t const c, char *opt, int fd)
{
	u_char		utf8[5];
	ssize_t		len;
	size_t		size;
	ssize_t		ret;

	ret = 0;
	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	if (c == 0)
	{
		if (!size)
			return (1);
		return (ft_putnchar_fd(opt[PF_PADC], size, fd));
	}
	ft_bzero(utf8, 5 * sizeof(u_char));
	ft_wc_to_utf8(c, utf8);
	len = (ssize_t)size - (ssize_t)ft_strlen((char *)utf8);
	if (len > 0)
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	ret += ft_putstr_fd((char *)utf8, fd);
	return (ret);
}
