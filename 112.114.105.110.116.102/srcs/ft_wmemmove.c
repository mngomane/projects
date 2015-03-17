/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmemmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 10:04:45 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/17 10:04:45 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wmemmove(wchar_t *dst, const wchar_t *src, size_t len)
{
	return ((wchar_t *)ft_memmove(dst, src, len * sizeof(wchar_t)));
}
