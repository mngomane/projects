/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnulong_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 21:45:43 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 21:45:43 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_buffer(wchar_t **buf, u_long n)
{
	u_long		decim;
	int			index;

	index = 0;
	decim = 1;
	while (decim && (n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		(*buf)[index++] = ((n / decim) % 10) + '0';
		decim /= 10;
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

ssize_t			ft_printnulong_fd(u_long n, char *opt, int fd)
{
	wchar_t		*buf;
	ssize_t		len;
	ssize_t		ret;

	if (n == 0 && opt[PF_DOT])
		return (0);
	ret = 0;
	buf = ft_memalloc(25 * sizeof(wchar_t));
	fill_buffer(&buf, n);
	len = (ssize_t)get_size(opt) - (ssize_t)ft_wcslen(buf);
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
