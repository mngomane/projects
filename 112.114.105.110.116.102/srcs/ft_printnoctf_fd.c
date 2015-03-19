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

ssize_t		ft_printnoctf_fd(uintptr_t p, char *o, size_t size, int fd)
{
	wchar_t		*buf;
	ssize_t		len;

	if (p == 0)
		return (write(fd, "0", 1));
	buf = ft_memalloc(25 * sizeof(wchar_t));
	fill_buffer(&buf, p);
	len = (ssize_t)size - ((ssize_t)ft_wcslen(buf) + 1);
	if (len > 0)
	{
		len = ft_putnchar_fd(o[PF_PADC], (size_t)len, fd) + write(fd, "0", 1) +
			ft_putwstr_fd(buf, fd);
		free(buf);
		return (len);
	}
	free(buf);
	return (write(fd, "0", 1) + ft_putwstr_fd(buf, fd));
}
