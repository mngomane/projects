/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ztom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 18:36:21 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 18:36:21 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void		ft_ztom(void *dst, const size_t size)
{
	u_char	*tmp;
	int8_t	byte;

	byte = 0;
	tmp = dst;
	while (byte < 8)
		*(tmp++) = (((size_t)size >> (byte++ * 8)) & 0xff);
}
