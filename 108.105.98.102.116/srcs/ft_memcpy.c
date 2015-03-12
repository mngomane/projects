/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:03 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:03 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	index;

	index = 0;
	source = (char *)src;
	destination = dst;
	while (index < n)
	{
		destination[index] = source[index];
		++index;
	}
	dst = destination;
	return (dst);
}
