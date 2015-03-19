/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnoct_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 00:20:08 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 00:20:08 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnoct_fd(uintptr_t p, char *opt, int fd)
{
	wchar_t		*buf;
	uintptr_t	oct;
	ssize_t		len;
	int			index;
	size_t		size;
	ssize_t		ret;

	ret = 0;
	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	index = 0;
	oct = 1;
	if (p == 0 && opt[PF_DOT])
		return (0);
	buf = ft_memalloc(25 * sizeof(wchar_t));
	while (oct && (p / oct) > 8)
		oct *= 8;
	while (oct > 0)
	{
		buf[index++] = ((p / oct) % 8) + '0';
		oct /= 8;
	}
	len = (ssize_t)size - (ssize_t)ft_wcslen(buf);
	if (ft_wcslen(buf) < ft_mtoz(opt + PF_PERIOD))
		len -= (ssize_t)ft_mtoz(opt + PF_PERIOD) - (ssize_t)ft_wcslen(buf);
	if (len > 0)
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	if (ft_wcslen(buf) < ft_mtoz(opt + PF_PERIOD))
		ret += ft_putnchar_fd(opt[PF_DOTC], ft_mtoz(opt + PF_PERIOD) -
			ft_wcslen(buf), fd);
	ret += ft_putwstr_fd(buf, fd);
	free(buf);
	return (ret);
}
