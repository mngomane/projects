/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 00:45:13 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 00:45:13 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putendl_fd(char const *s, int fd)
{
	ssize_t		ret;

	ret = 0;
	if (s == (void *)0)
		ret = ft_putstr_fd("(null)", fd);
	else if ((ret = ft_putstr_fd(s, fd)) < 0)
		return (-1);
	ft_putchar_fd('\n', fd);
	return (ret + 1);
}
