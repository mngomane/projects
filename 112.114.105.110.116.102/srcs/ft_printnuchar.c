/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnuchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 23:27:59 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 23:27:59 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnuchar(u_char n, int padc, size_t size, int sign)
{
	if (sign)
		return (write(1, "+", 1) + ft_printnuchar_fd(n, padc, size, 1));
	return (ft_printnuchar_fd(n, padc, size, 1));
}
