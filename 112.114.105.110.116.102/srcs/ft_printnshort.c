/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnshort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 23:35:54 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 23:35:54 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnshort(short n, int padc, size_t size, int sign)
{
	if (n >= 0 && sign && size > 0)
		return (write(1, &sign, 1) + ft_printnshort_fd(n, padc, size - 1, 1));
	if (n >= 0 && sign)
		return (write(1, &sign, 1) + ft_printnshort_fd(n, padc, 0, 1));
	return (ft_printnshort_fd(n, padc, size, 1));
}
