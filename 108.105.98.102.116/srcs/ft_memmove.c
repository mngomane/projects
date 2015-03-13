/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:09 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:09 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bcopy (char *src, char *dst, int len)
{
	char	*last_src;
	char	*last_dst;

	last_src = src + (len - 1);
	last_dst = dst + (len - 1);
	if (dst < src)
	{
		while (len--)
			*dst++ = *src++;
	}
	else
	{
		while (len--)
			*(char *)last_dst-- = *(char *)last_src--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	ft_bcopy((char *)src, dst, (int)len);
	return (dst);
}
