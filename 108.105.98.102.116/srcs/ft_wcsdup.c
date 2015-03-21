/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:04:10 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/17 13:04:10 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcsdup(wchar_t const *wstr)
{
	wchar_t	*copy;
	size_t	len;

	len = ft_wcslen(wstr) + 1;
	if ((copy = malloc(len * sizeof(wchar_t))) == (void *)0)
		return ((void *)0);
	return (ft_wmemcpy(copy, wstr, len));
}
