/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 00:46:57 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 00:46:57 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		decim;
	char	c;

	decim = ((n == -2147483648) ? 0 : 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if ((n > -2147483648) && (n < 0))
	{
		c = '-';
		write(fd, &c, 1);
		n *= -1;
	}
	while (decim && (n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		c = ((n / decim) % 10) + '0';
		write(fd, &c, 1);
		decim /= 10;
	}
}
