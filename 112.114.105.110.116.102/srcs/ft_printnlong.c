/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnlong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 22:59:24 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 22:59:24 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnlong(long n, char *opt, size_t size)
{
	int		sign;

	sign = opt[PF_SIGN];
	if (n >= 0 && sign && size > 0)
		return (write(1, &sign, 1) + ft_printnlong_fd(n, opt, size - 1, 1));
	if (n >= 0 && sign)
		return (write(1, &sign, 1) + ft_printnlong_fd(n, opt, 0, 1));
	return (ft_printnlong_fd(n, opt, size, 1));
}
