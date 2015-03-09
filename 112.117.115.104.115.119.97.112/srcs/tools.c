/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 03:10:23 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/10 03:10:23 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*str_min_int(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	str = ft_memcpy(str, "-2147483648", 12);
	return (str);
}

void	ft_putnbr(int n)
{
	int		decim;
	char	c;

	decim = ((n == -2147483648) ? 0 : 1);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if ((n > -2147483648) && (n < 0))
	{
		c = '-';
		write(1, &c, 1);
		n *= -1;
	}
	while (decim && (n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		c = ((n / decim) % 10) + '0';
		write(1, &c, 1);
		decim /= 10;
	}
}

int		ft_strncmp(char *s1, char *s2, size_t len)
{
	if (*s1 != *s2 && (ft_strlen(s1) == 0 || ft_strlen(s2) == 0))
		return (-1);
	if (*s1 == *s2 && ft_strlen(s1) == 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && len > 1)
	{
		++s1;
		++s2;
		--len;
	}
	if (len == 1)
	{
		if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		{
			++s1;
			++s2;
			--len;
		}
	}
	if (*s2 == '\0' && len == 0)
		return (0);
	return ((int)(*s1 - *s2));
}
