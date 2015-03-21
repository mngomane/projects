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

ssize_t		ft_printnc_fd(int c, char *opt, int fd)
{
	size_t		size;
	ssize_t		ret;

	ret = 0;
	if (opt[PF_MINUS] == 1)
		size = 0;
	else
		size = ft_mtoz(opt + PF_PREC);
	if (size > 1)
		ret += ft_putnchar_fd(opt[PF_PADC], (size - 1), fd);
	ret += write(1, &c, 1);
	return (ret);
}
