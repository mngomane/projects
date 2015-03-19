/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnwstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 01:41:52 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 01:41:52 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnwstr_fd(wchar_t const *s, int p, size_t z, int fd)
{
	ssize_t		ret;
	ssize_t		len;

	ret = 0;
	if (s == (void *)0)
	{
		if (z > 6)
			return (ft_putnchar_fd(p, (z - 6), fd) + write(fd, "(null)", 6));
		return (ft_putstr_fd("(null)", fd));
	}
	len = (ssize_t)z - (ssize_t)ft_wcslen(s);
	if (len > 0)
		ret += ft_putnchar_fd(p, (size_t)len, fd);
	while (*s)
		ret += ft_putwchar_fd(*(s++), fd);
	return (ret);
}
