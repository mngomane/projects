/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:32 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:32 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*duplicate;
	size_t	length;
	size_t	index;

	index = 0;
	length = ft_strlen(s1);
	duplicate = (char *)malloc(sizeof(char) * (length + 1));
	while (index < length)
	{
		duplicate[index] = s1[index];
		++index;
	}
	duplicate[index] = '\0';
	return (duplicate);
}
