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

#include "ft_string.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	u_char	*string1;
	u_char	*string2;
	size_t			size;

	string1 = (u_char *)s1;
	string2 = (u_char *)s2;
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
