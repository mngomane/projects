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

	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	index = 0;
	oct = 1;
	buf = ft_memalloc(25 * sizeof(wchar_t));
	while (oct && (p / oct) > 8)
		oct *= 8;
	while (oct > 0)
	{
		buf[index++] = ((p / oct) % 8) + '0';
		oct /= 8;
	}
	len = (ssize_t)size - (ssize_t)ft_wcslen(buf);
	if (len > 0)
	{
		len = ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd) +
			ft_putwstr_fd(buf, fd);
		free(buf);
		return (len);
	}
	free(buf);
	return (ft_putwstr_fd(buf, fd));
}
