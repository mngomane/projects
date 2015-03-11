/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:24:08 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:24:08 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	index;

	if (n != 0)
	{
		index = 0;
		string = s;
		while (index < n)
		{
			string[index] = '\0';
			++index;
		}
		s = string;
	}
}
