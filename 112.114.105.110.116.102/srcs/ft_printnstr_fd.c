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

ssize_t		ft_printnstr_fd(char const *s, int p, size_t z, int fd)
{
	ssize_t		len;

	if (s == (void *)0)
	{
		if (z > 6)
			return (ft_putnchar_fd(p, (z - 6), fd) + write(fd, "(null)", 6));
		return (write(fd, "(null)", 6));
	}
	len = (ssize_t)z - (ssize_t)ft_strlen(s);
	if (len > 0)
	{
		len = ft_putnchar_fd(p, (size_t)len, fd) + write(fd, s, ft_strlen(s));
		return (len);
	}
	return (write(fd, s, ft_strlen(s)));
}
