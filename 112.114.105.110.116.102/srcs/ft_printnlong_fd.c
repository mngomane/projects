/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnlong_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 22:11:18 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 22:11:18 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_buffer(wchar_t **buf, long n)
{
	long	decim;
	int		index;

	index = 0;
	decim = ((n == (-9223372036854775807 - 1)) ? 0 : 1);
	if (n == (-9223372036854775807 - 1))
		ft_wcscpy(*buf, L"-9223372036854775808");
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

static size_t	get_size(long n, char *opt, ssize_t *ret, int fd)
{
	size_t		size;
	int			sign;

	sign = opt[PF_SIGN];
	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	if (n >= 0 && sign)
	{
		*ret += write(fd, &sign, 1);
		size--;
	}
	return (size);
}

static ssize_t	init_ret(long n, char *opt, wchar_t **buf, int fd)
{
	ssize_t		ret;
	ssize_t		len;

	ret = 0;
	len = (ssize_t)get_size(n, opt, &ret, fd) - (ssize_t)ft_wcslen(*buf);
	if (ft_wcslen(*buf) < ft_mtoz(opt + PF_PERIOD))
	{
		if ((*buf)[0] == '-')
			len--;
		len -= (ssize_t)ft_mtoz(opt + PF_PERIOD) - (ssize_t)ft_wcslen(*buf);
	}
	if (len > 0)
	{
		if (n < 0 && opt[PF_PADC] == '0')
		{
			(*buf)[0] = '0';
			len--;
			ret += write(fd, "-", 1);
		}
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	}
	return (ret);
}

ssize_t			ft_printnlong_fd(long n, char *opt, int fd)
{
	wchar_t		*buf;
	ssize_t		ret;

	if (n == 0 && opt[PF_DOT])
		return (0);
	buf = ft_memalloc(25 * sizeof(wchar_t));
	fill_buffer(&buf, n);
	ret = init_ret(n, opt, &buf, fd);
	if (ft_wcslen(buf) < ft_mtoz(opt + PF_PERIOD))
	{
		if (buf[0] == '-')
		{
			buf[0] = '0';
			ret += write(fd, "-", 1);
		}
		ret += ft_putnchar_fd(opt[PF_DOTC], ft_mtoz(opt + PF_PERIOD) -
			ft_wcslen(buf), fd);
	}
	ret += ft_putwstr_fd(buf, fd);
	free(buf);
	return (ret);
}
