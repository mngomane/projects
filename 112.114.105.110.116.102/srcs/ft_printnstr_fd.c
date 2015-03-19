/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 02:00:33 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 02:00:33 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnstr_fd(char const *s, char *opt, int fd)
{
	ssize_t		len;
	size_t		size;

	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	if (s == (void *)0)
	{
		if (size > 6)
			return (ft_putnchar_fd(opt[PF_PADC], (size - 6), fd) +
				write(fd, "(null)", 6));
		return (write(fd, "(null)", 6));
	}
	len = (ssize_t)size - (ssize_t)ft_strlen(s);
	if (len > 0)
	{
		len = ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd) +
			write(fd, s, ft_strlen(s));
		return (len);
	}
	return (write(fd, s, ft_strlen(s)));
}
