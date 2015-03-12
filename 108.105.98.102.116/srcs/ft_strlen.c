/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:40 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:40 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*origin;
	char	*string;

	origin = (char *)s;
	string = (char *)s;
	if (string == NULL)
	{
		return (0);
	}
	while (*string != '\0')
	{
		++string;
	}
	return ((size_t)(string - origin));
}
