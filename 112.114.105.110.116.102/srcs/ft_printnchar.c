/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 23:41:19 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 23:41:19 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnchar(char n, int padc, size_t size, int sign)
{
	if (n >= 0 && sign)
		return (write(1, "+", 1) + ft_printnchar_fd(n, padc, size, 1));
	return (ft_printnchar_fd(n, padc, size, 1));
}
