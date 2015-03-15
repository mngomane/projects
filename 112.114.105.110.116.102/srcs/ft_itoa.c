/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 00:19:46 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 00:19:46 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		decim;
	size_t	index;

	index = 0;
	decim = ((n == -2147483648) ? 0 : 1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_strnew(11);
	if ((n > -2147483648) && (n < 0))
	{
		str[index++] = '-';
		n *= -1;
	}
	while (decim && (n / decim) > 9)
		decim *= 10;
	while (decim > 0)
	{
		str[index++] = ((n / decim) % 10) + '0';
		decim /= 10;
	}
	return (str);
}
