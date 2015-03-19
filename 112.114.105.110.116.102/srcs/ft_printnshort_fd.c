/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnshort_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 23:32:25 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 23:32:25 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_buffer(wchar_t **buf, short n)
{
	short	decim;
	int		index;

	index = 0;
	decim = ((n == -32768) ? 0 : 1);
	if (n == -32768)
		ft_wcscpy(*buf, L"-32768");
	else if (n < 0)
	{
		(*buf)[index++] = L'-';
		n *= -1;
	}
	while (decim && (n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		(*buf)[index++] = ((n / decim) % 10) + '0';
		decim /= 10;
	}
}

ssize_t		ft_printnshort_fd(short n, int padc, size_t size, int fd)
{
	wchar_t	*buf;
	ssize_t	len;

	buf = ft_memalloc(25 * sizeof(wchar_t));
	fill_buffer(&buf, n);
	len = (ssize_t)size - (ssize_t)ft_wcslen(buf);
	if (len > 0)
	{
		if (n < 0 && padc == '0')
		{
			buf[0] = '0';
			len--;
			write(fd, "-", 1);
		}
		len = ft_putnchar_fd(padc, (size_t)len, fd) + ft_putwstr_fd(buf, fd);
		len += (n < 0 && padc == '0' ? 1 : 0);
		free(buf);
		return (len);
	}
	free(buf);
	return (ft_putwstr_fd(buf, fd));
}