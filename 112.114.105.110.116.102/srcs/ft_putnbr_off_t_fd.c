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

int		ft_putnbr_off_t_fd(off_t n, int fd)
{
	char	c;
	size_t	ret;
	off_t	decim;

	decim = 1;
	ret = 0;
	while ((n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		c = (n / decim) % 10 + '0';
		write(fd, &c, 1);
		++ret;
		decim /= 10;
	}
	return ((int)ret);
}
