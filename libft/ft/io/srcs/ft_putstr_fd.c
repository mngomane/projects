/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 00:43:47 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 00:43:47 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

ssize_t		ft_putstr_fd(char const *s, int fd)
{
	if (s == (void *)0)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}
