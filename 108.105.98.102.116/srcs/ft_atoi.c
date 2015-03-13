/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:23:55 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:23:55 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned char	*string;
	int		result;
	int		sign;

	string = (unsigned char *)str;
	result = 0;
	sign = 1;
	while (*string == ' ' || *string == '\n' || *string == '\t' ||
			*string == '\r' || *string == '\v' || *string == '\f')
		++string;
	if (*string == '+' || *string == '-')
	{
		sign = ((*string == '-') ? -1 : 1);
		++string;
	}
	while (*string >= '0' && *string <= '9')
	{
		result *= 10;
		result += *string - '0';
		++string;
	}
	return (sign * result);
}
