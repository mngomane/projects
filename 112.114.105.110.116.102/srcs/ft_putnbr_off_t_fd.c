/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_off_t_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 13:16:17 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/15 13:16:17 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putnbr_off_t_fd(off_t n, int fd)
{
	char	c;
	ssize_t	ret;
	off_t	decim;

	decim = 1;
	ret = 0;
	while ((n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		c = (n / decim) % 10 + '0';
		if (write(fd, &c, 1) < 0)
			return (-1);
		++ret;
		decim /= 10;
	}
	return (ret);
}
