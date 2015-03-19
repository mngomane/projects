/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnhexu_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 00:14:20 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 00:14:20 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_buffer(wchar_t **buf, uintptr_t p)
{
	uintptr_t	hex;
	int			index;

	index = 0;
	hex = 1;
	while (hex && (p / hex) >= 16)
		hex *= 16;
	while (hex > 0)
	{
		(*buf)[index] = (p / hex) % 16;
		(*buf)[index] += (((*buf)[index] < 10) ? '0' : 'A' - 10);
		index++;
		hex /= 16;
	}
}

ssize_t		ft_printnhexu_fd(uintptr_t p, int c, size_t size, int fd)
{
	wchar_t		*buf;
	ssize_t		len;

	buf = ft_memalloc(25 * sizeof(wchar_t));
	fill_buffer(&buf, p);
	len = (ssize_t)size - (ssize_t)ft_wcslen(buf);
	if (len > 0)
	{
		len = ft_putnchar_fd(c, (size_t)len, fd) + ft_putwstr_fd(buf, fd);
		free(buf);
		return (len);
	}
	free(buf);
	return (ft_putwstr_fd(buf, fd));
}
