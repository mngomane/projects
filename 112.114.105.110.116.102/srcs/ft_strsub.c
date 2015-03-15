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
	if (!str)
		return ((void *)0);
	index = 0;
	while (s && *s && start--)
		s++;
	while (s && *s && index < len)
	{
		str[index++] = *s;
		++s;
	}
	str[index] = '\0';
	return (str);
}
