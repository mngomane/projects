/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcscpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 22:26:21 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 22:26:21 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcscpy(wchar_t *dst, wchar_t const *src)
{
	wchar_t	*tmp;
	size_t	index;

	index = 0;
	tmp = dst;
	while (src[index] != L'\0')
		*(tmp++) = src[index++];
	*tmp = L'\0';
	return (dst);
}
