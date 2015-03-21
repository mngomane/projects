/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putushort_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 03:04:15 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 03:04:15 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putushort_fd(u_short n, int fd)
{
	char	c;
	u_short	decim;
	ssize_t	ret;

	ret = 0;
	decim = 1;
	while (decim && (n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		c = ((n / decim) % 10) + '0';
		if (write(fd, &c, 1) < 0)
			return (-1);
		++ret;
		decim /= 10;
	}
	return (ret);
}
