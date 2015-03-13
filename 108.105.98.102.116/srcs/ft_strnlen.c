/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 16:58:32 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/13 16:58:32 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t size)
{
	char	*origin;
	char	*string;

	origin = (char *)s;
	string = (char *)s;
	if (string == (void *)0)
		return (0);
	while (*string != '\0' && size--)
		++string;
	return ((size_t)(string - origin));
}
