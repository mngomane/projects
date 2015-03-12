/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:09 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:09 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*destination;
	char	*source;
	size_t	index;

	index = 0;
	source = (char *)src;
	destination = (char *)dst;
	while (index < len)
	{
		destination[index] = source[index];
		++index;
	}
	dst = (void *)destination;
	return (dst);
}
