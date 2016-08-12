/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:23 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:23 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strchr(const char *s, int c)
{
	char	*first_occurrence;

	first_occurrence = (char *)s;
	while (*first_occurrence != '\0')
	{
		if (*first_occurrence == (char)c)
			return (first_occurrence);
		++first_occurrence;
	}
	if (*first_occurrence == (char)c)
		return (first_occurrence);
	return ((void *)0);
}
