/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:55 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:55 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = (char *)s;
	while (*last_occurrence != '\0')
		++last_occurrence;
	while ((last_occurrence - s) >= 0)
	{
		if (*last_occurrence == (char)c)
		{
			return (last_occurrence);
		}
		--last_occurrence;
	}
	return ((void *)0);
}
