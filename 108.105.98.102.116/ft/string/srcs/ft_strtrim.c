/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 23:24:38 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/13 23:24:38 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	index;

	index = 0;
	len = ft_strlen(s);
	str = ft_strnew(len);
	while (s && (*s == ' ' || *s == '\t' || *s == '\n'))
		++s;
	while (s && *s)
		str[index++] = *(s++);
	--s;
	--index;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		str[index--] = '\0';
		--s;
	}
	return (str);
}
