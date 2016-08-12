/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:24:46 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:24:46 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*destination;
	char	*source;
	char	*copy;
	size_t	index;

	index = 0;
	source = (char *)src;
	copy = dst;
	destination = dst;
	if (!n)
		return ((void *)0);
	while (index < n)
	{
		destination[index] = source[index];
		++copy;
		if (source[index] == c)
		{
			dst = destination;
			return (destination + index + 1);
		}
		++index;
	}
	dst = destination;
	return ((void *)0);
}
