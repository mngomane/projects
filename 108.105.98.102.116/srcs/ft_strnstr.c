/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:52 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:52 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*occurrence;
	size_t	index;

	occurrence = (char *)s1;
	index = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*occurrence != '\0' && s2[index] != '\0' && (size_t)(occurrence - (char *)s1) < n)
	{
		if (*occurrence == s2[index])
			++index;
		else
		{
			occurrence -= index;
			index = 0;
		}
		++occurrence;
	}
	if (s2[index] == 0)
		return (occurrence - index);
	return (NULL);
}
