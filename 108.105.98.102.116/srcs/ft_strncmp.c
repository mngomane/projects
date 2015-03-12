/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:47 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:47 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			size;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	size = 0;
	if (!n)
		return (0);
	while (*string1 != '\0' && *string2 != '\0' && size < n)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		++size;
		if (size < n)
		{
			++string1;
			++string2;
		}
	}
	return (*string1 - *string2);
}
