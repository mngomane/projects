/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 19:32:45 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 19:32:46 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

ssize_t			ft_putnchar_fd(int c, size_t rep, int fd)
{
	ssize_t		ret;

	ret = 0;
	while (rep-- && ft_putchar_fd(c, fd))
		++ret;
	return (ret);
}
