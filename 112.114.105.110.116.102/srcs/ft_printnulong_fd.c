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

ssize_t		ft_printnulong_fd(u_long n, char *opt, int fd)
{
	int			index;
	u_long		decim;
	wchar_t		*buf;
	ssize_t		len;
	size_t		size;
	ssize_t		ret;

	ret = 0;
	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	decim = 1;
	index = 0;
	if (n == 0 && opt[PF_DOT])
		return (0);
	buf = ft_memalloc(25 * sizeof(wchar_t));
	while (decim && (n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		buf[index++] = ((n / decim) % 10) + '0';
		decim /= 10;
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
