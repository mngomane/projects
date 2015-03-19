/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 01:01:05 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 01:01:05 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnint(int n, int padc, size_t size, int sign)
{
	if (n >= 0 && sign)
		return (write(1, "+", 1) + ft_printnint_fd(n, padc, size, 1));
	return (ft_printnint_fd(n, padc, size, 1));
}
