/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 03:09:21 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 03:09:21 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s1, size_t size)
{
	char	*dup;
	size_t	index;

	index = 0;
	if (!size || !s1)
		return ((void *)0);
	dup = (char *)malloc(size);
	while (index < size)
	{
		dup[index] = ((char *)s1)[index];
		++index;
	}
	return ((void *)dup);
}
