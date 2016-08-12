/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putshort_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 02:59:16 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 02:59:16 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

ssize_t			ft_putshort_fd(short n, int fd)
{
	char		c;
	short		decim;
	ssize_t		ret;

	ret = 0;
	decim = 1;
	if (n == -32768)
		return (write(fd, "-32768", 6));
	else if (n < 0)
	{
		ret = write(fd, "-", 1);
		n *= -1;
	}
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
