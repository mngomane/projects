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

#include "libft.h"

ssize_t		ft_putwchar_fd(int ucs2, int fd)
{
	u_char	utf8[5];

	ft_bzero(&utf8, 5 * sizeof(u_char));
	ft_ucs2_to_utf8(ucs2, utf8);
	return (ft_putstr_fd((char *)utf8, fd));
}
