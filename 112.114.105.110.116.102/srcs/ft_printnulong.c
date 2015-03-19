/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnulong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 22:03:38 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 22:03:38 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnulong(u_long n, int padc, size_t size, int sign)
{
	if (sign)
		return (write(1, "+", 1) + ft_printnulong_fd(n, padc, size, 1));
	return (ft_printnulong_fd(n, padc, size, 1));
}
