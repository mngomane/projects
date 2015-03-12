/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:16 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:16 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		index;
	unsigned char	*string;

	index = 0;
	string = b;
	while (index < len)
	{
		string[index] = (unsigned char)c;
		++index;
	}
	b = string;
	return (b);
}
