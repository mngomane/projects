/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 22:20:18 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/17 22:20:18 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t			ft_putwstr_fd(wchar_t const *wstr, int fd)
{
	ssize_t		ret;

	ret = 0;
	if (wstr == (void *)0)
		return (ft_putstr_fd("(null)", fd));
	while (*wstr)
		ret += ft_putwchar_fd(*(wstr++), fd);
	return (ret);
}
