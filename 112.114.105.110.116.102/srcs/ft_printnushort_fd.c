/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnushort_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 23:17:57 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 23:17:57 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnushort_fd(u_short n, char *opt, int fd)
{
	int		index;
	u_short	decim;
	wchar_t	*buf;
	ssize_t	len;
	size_t	size;

	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	decim = 1;
	index = 0;
	buf = ft_memalloc(25 * sizeof(wchar_t));
	while (decim && (n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		buf[index++] = ((n / decim) % 10) + '0';
		decim /= 10;
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
