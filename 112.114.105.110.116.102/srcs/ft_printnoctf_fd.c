/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnoctf_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 13:01:14 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 13:01:14 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_buffer(wchar_t **buf, uintptr_t p)
{
	uintptr_t	oct;
	int			index;

	index = 0;
	oct = 1;
	while (oct && (p / oct) > 8)
		oct *= 8;
	while (oct > 0)
	{
		(*buf)[index++] = ((p / oct) % 8) + '0';
		oct /= 8;
	}
}

ssize_t		ft_printnoctf_fd(uintptr_t p, char *opt, int fd)
{
	wchar_t		*buf;
	ssize_t		len;
	size_t		size;
	ssize_t		ret;

	ret = 0;
	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	if (p == 0)
		return (write(fd, "0", 1));
	buf = ft_memalloc(25 * sizeof(wchar_t));
	fill_buffer(&buf, p);
	len = (ssize_t)size - ((ssize_t)ft_wcslen(buf) + 1);
	if (ft_wcslen(buf) < ft_mtoz(opt + PF_PERIOD))
		ret += (ssize_t)ft_mtoz(opt + PF_PERIOD) - (ssize_t)ft_wcslen(buf);
	if (len > 0)
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	if (ft_wcslen(buf) < ft_mtoz(opt + PF_PERIOD))
		ret += ft_putnchar_fd(opt[PF_DOTC], ft_mtoz(opt + PF_PERIOD) -
			ft_wcslen(buf), fd);
	ret += write(fd, "0", 1) + ft_putwstr_fd(buf, fd);
	free(buf);
	return (ret);
}
