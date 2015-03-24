/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:31:13 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/16 22:31:13 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t			ft_putwchar_fd(wchar_t const wc, int fd)
{
	u_char		utf8[5];

	if (wc == 0)
		return (1);
	ft_bzero(utf8, 5 * sizeof(u_char));
	ft_wc_to_utf8(wc, utf8);
	return (ft_putstr_fd((char *)utf8, fd));
}
