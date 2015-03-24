/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 17:37:41 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/13 17:37:41 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	index;

	index = 0;
	str = ft_strnew(ft_strlen(s));
	while (s && s[index])
	{
		str[index] = f(s[index]);
		++index;
	}
	return (str);
}
