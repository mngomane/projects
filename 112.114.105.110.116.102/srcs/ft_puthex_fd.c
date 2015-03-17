/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 13:59:01 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/16 13:59:01 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_puthex_fd(uintptr_t p, int fd)
{
	char		c;
	uintptr_t	hex;
	ssize_t		ret;

	hex = 1;
	ret = 0;
	while ((p / hex) >= 16)
		hex *= 16;
	while (hex > 0)
	{
		c = (p / hex) % 16;
		c += ((c < 10) ? '0' : 'a' - 10);
		if (write(fd, &c, 1) < 0)
			return (-1);
		++ret;
		hex /= 16;
	}
	return (ret);
}
