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

ssize_t		ft_printnlong_fd(long n, char *opt, int fd)
{
	wchar_t	*buf;
	ssize_t	len;
	ssize_t	ret;
	int		sign;
	size_t	size;

	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	sign = opt[PF_SIGN];
	ret = 0;
	buf = ft_memalloc(25 * sizeof(wchar_t));
	fill_buffer(&buf, n);
	if (n >= 0 && sign)
	{
		ret += write(1, &sign, 1);
		size--;
	}
	len = (ssize_t)size - (ssize_t)ft_wcslen(buf);
	if (ft_wcslen(buf) < ft_mtoz(opt + PF_PERIOD))
		len -= (ssize_t)ft_mtoz(opt + PF_PERIOD) - (ssize_t)ft_wcslen(buf);
	if (len > 0)
	{
		if (n < 0 && opt[PF_PADC] == '0')
		{
			buf[0] = '0';
			len--;
			ret += write(fd, "-", 1);
		}
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	}
	if (ft_wcslen(buf) < ft_mtoz(opt + PF_PERIOD))
		ret += ft_putnchar_fd(opt[PF_DOTC], ft_mtoz(opt + PF_PERIOD) -
			ft_wcslen(buf), fd);
	ret += ft_putwstr_fd(buf, fd);
	free(buf);
	return (ret);
}
