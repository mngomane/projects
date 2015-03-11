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

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	unsigned char	*copy;
	size_t		index;

	index = 0;
	source = (unsigned char *)src;
	copy = dst;
	destination = dst;
	while (index < n && *copy != '\0')
	{
		destination[index] = source[index];
		++copy;
		if (source[index] == (unsigned char)c)
		{
			dst = destination;
			return (copy);
		}
		++index;
	}
	dst = destination;
	return (NULL);
}
