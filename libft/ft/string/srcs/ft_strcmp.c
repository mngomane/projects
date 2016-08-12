/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:26 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:26 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	u_char	*string1;
	u_char	*string2;

	string1 = (u_char *)s1;
	string2 = (u_char *)s2;
	while (*string1 != '\0' && *string2 != '\0')
	{
		if (*string1 != *string2)
			return ((int)(*string1 - *string2));
		++string1;
		++string2;
	}
	return ((int)(*string1 - *string2));
}
