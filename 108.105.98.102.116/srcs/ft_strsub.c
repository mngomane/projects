/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 18:08:13 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/13 18:08:13 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	str = ft_strnew(len);
	index = 0;
	while (start--)
		s++;
	while (index < len)
	{
		str[index] = *s;
		++s;
	}
	return (str);
}
