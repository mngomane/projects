/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 13:31:38 by mngomane          #+#    #+#             */
/*   Updated: 2014/05/04 16:21:43 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

size_t	ft_strlen(char *str)
{
	char	*origin;

	origin = str;
	if (str == (void *)0)
		return (0);
	while (*str != '\0')
		++str;
	return ((size_t)(str - origin));
}

int		ft_putchar(int c)
{
	write(1, &c, 1);
	return (c);
}

void	*ft_memset(void *s, int c, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	tmp = (char *)s;
	while (i < len)
	{
		tmp[i] = (char)c;
		++i;
	}
	return ((void *)tmp);
}
