/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnhexuf_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 13:28:56 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 13:28:56 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_buffer(wchar_t **buf, uintptr_t p)
{
	uintptr_t	hex;
	int			index;

	index = 0;
	hex = 1;
	while (hex && (p / hex) > 15)
		hex *= 16;
	while (hex > 0)
	{
		(*buf)[index] = (p / hex) % 16;
		(*buf)[index] += (((*buf)[index] < 10) ? '0' : 'A' - 10);
		index++;
		hex /= 16;
	}
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

ssize_t			ft_printnhexuf_fd(uintptr_t p, char *opt, int fd)
{
	wchar_t		*buf;
	ssize_t		len;
	ssize_t		ret;

	if (p == 0)
		return (write(fd, "0", 1));
	ret = 0;
	buf = ft_memalloc(25 * sizeof(wchar_t));
	fill_buffer(&buf, p);
	len = (ssize_t)get_size(opt) - ((ssize_t)ft_wcslen(buf) + 2);
	if (len > 0)
	{
		if (opt[PF_PADC] == '0')
			ret += write(fd, "0X", 2) + ft_putnchar_fd(opt[PF_PADC],
				(size_t)len, fd) + ft_putwstr_fd(buf, fd);
		else
			ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd) +
				write(fd, "0X", 2) + ft_putwstr_fd(buf, fd);
	}
	else
		ret += write(fd, "0X", 2) + ft_putwstr_fd(buf, fd);
	free(buf);
	return (ret);
}
