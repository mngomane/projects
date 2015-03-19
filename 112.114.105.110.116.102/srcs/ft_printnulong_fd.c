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

ssize_t		ft_printnulong_fd(u_long n, char *opt, size_t size, int fd)
{
	int		index;
	u_long	decim;
	wchar_t	*buf;
	ssize_t	len;

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
		len = ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd) + ft_putwstr_fd(buf, fd);
		free(buf);
		return (len);
	}
	free(buf);
	return (ft_putwstr_fd(buf, fd));
}
