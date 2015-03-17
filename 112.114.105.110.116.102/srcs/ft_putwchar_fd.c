/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:31:13 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/16 22:31:13 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putwchar_fd(uintptr_t p, int fd)
{
	uintptr_t	hex;
	ssize_t		ret;
	int8_t		i;
	int			c[4];

	i = 0;
	hex = 1;
	ret = 0;
	while ((p / hex) > 16)
		hex *= 16;
	while (hex > 0 && i < 4)
	{
		c[3 - i] += (p / hex) % 16;
		++i;
		hex /= 16;
	}
	if ((ret = write(fd, c, 4)) < 0)
		return (-1);
	return (ret);
}
