/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:19 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:19 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strcat(char *s1, const char *s2)
{
	size_t	index;
	size_t	source_index;

	index = 0;
	source_index = 0;
	while (s1[index] != '\0')
	{
		++index;
	}
	while (s2[source_index] != '\0')
	{
		s1[index] = s2[source_index];
		++index;
		++source_index;
	}
	s1[index] = '\0';
	return (s1);
}
