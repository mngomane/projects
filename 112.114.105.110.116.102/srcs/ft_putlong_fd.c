/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 00:33:48 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 00:33:48 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putlong_fd(long n, int fd)
{
	char	c;
	long	decim;
	ssize_t	ret;

	ret = 0;
	decim = 1;
	while (decim && (n / decim) > 9)
		decim *= 10;
	if (n == (-9223372036854775807 - 1))
		return (write(fd, "-9223372036854775808", 20));
	else if (n < 0)
	{
		ret = write(fd, "-", 1);
		n *= -1;
	}
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
