/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnc_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 02:20:31 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 02:20:31 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_printnc_fd(int c, char *opt, size_t size, int fd)
{
	if (size > 1)
		return (ft_putnchar_fd(opt[PF_PADC], (size - 1), fd) + write(1, &c, 1));
	return (write(1, &c, 1));
}
