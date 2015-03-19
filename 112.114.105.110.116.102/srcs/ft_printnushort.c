/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnushort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 23:21:35 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 23:21:35 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnushort(u_short n, int padc, size_t size, int s)
{
	if (s)
		return (write(1, "+", 1) + ft_printnushort_fd(n, padc, size, 1));
	return (ft_printnushort_fd(n, padc, size, 1));
}
