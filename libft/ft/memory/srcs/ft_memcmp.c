/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:24:55 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:24:55 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			index;

	index = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (index < n)
	{
		if (string1[index] != string2[index])
			return (string1[index] - string2[index]);
		++index;
	}
	return (0);
}
