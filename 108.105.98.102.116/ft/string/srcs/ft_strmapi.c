/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 17:45:36 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/13 17:45:36 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strmapi(char const *s, char (*f)(u_int, char))
{
	char	*str;
	u_int	index;

	index = 0;
	str = ft_strnew(ft_strlen(s));
	while (s && s[index])
	{
		str[index] = f(index, s[index]);
		++index;
	}
	return (str);
}
