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

static ssize_t	modifier_ret(char const *s, char *opt, int fd, size_t size)
{
	ssize_t		ret;
	ssize_t		len;

	ret = 0;
	if (opt[PF_DOT] && ft_mtoz(opt + PF_PERIOD) < ft_strlen(s))
		len = (ssize_t)size - (ssize_t)ft_mtoz(opt + PF_PERIOD);
	else
		len = (ssize_t)size - (ssize_t)ft_strlen(s);
	if (len > 0)
		ret += ft_putnchar_fd(opt[PF_PADC], (size_t)len, fd);
	if (opt[PF_DOT] && ft_mtoz(opt + PF_PERIOD) < ft_strlen(s))
		ret += write(fd, s, ft_mtoz(opt + PF_PERIOD));
	else
		ret += write(fd, s, ft_strlen(s));
	return (ret);
}

ssize_t			ft_printnstr_fd(char const *s, char *opt, int fd)
{
	size_t		size;
	ssize_t		ret;

	ret = 0;
	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	if (s == (void *)0)
	{
		if (size > 6)
			ret += ft_putnchar_fd(opt[PF_PADC], (size - 6), fd);
		ret += write(fd, "(null)", 6);
		return (ret);
	}
	return (modifier_ret(s, opt, fd, size));
}
