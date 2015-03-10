/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 22:43:43 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 17:43:05 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 != *s2 && (ft_strlen(s1) == 0 || ft_strlen(s2) == 0))
		return (-1);
	if (*s1 == *s2 && ft_strlen(s1) == 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		++s1;
		++s2;
	}
	return ((int)(*s1 - *s2));
}

size_t	ft_strlen(char *str)
{
	char	*origin;

	if (str == (void *)0)
		return (0);
	origin = str;
	while (*str != '\0')
		++str;
	return ((size_t)(str - origin));
}

void	ft_putnbr_off_t(off_t n)
{
	off_t	decim;
	char	c;

	decim = 1;
	while ((n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		c = (n / decim) % 10 + '0';
		write(1, &c, 1);
		decim /= 10;
	}
}
