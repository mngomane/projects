/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 02:49:34 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 02:49:34 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			index;

	string = (unsigned char *)s;
	index = 0;
	if (!n)
		return ((void *)0);
	while (index < n)
	{
		if (*string == (unsigned char)c)
			return (string);
		++string;
		++index;
	}
	return ((void *)0);
}
