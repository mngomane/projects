/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 18:46:19 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/16 18:46:19 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putoct_fd(uintptr_t p, int fd)
{
	char		c;
	uintptr_t	oct;
	ssize_t		ret;

	oct = 1;
	ret = 0;
	while ((p / oct) >= 8)
		oct *= 8;
	while (oct > 0)
	{
		c = ((p / oct) % 8) + '0';
		if (write(fd, &c, 1) < 0)
			return (-1);
		++ret;
		oct /= 8;
	}
	return (ret);
}
