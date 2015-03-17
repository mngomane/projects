/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmemcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:54:17 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/17 12:54:17 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wmemcpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	return ((wchar_t *)ft_memcpy(dst, src, len * sizeof(wchar_t)));
}
