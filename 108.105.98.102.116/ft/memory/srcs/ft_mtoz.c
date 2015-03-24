/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtoz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 18:50:20 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 18:50:20 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

size_t		ft_mtoz(void *src)
{
	int8_t	byte;
	size_t	ret;
	u_char	*tmp;

	ret = 0;
	byte = 0;
	tmp = src;
	while (byte < 8)
		ret += ((size_t)(*tmp++) << (byte++ * 8));
	return (ret);
}
