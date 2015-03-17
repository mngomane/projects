/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:48:46 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/17 12:48:46 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wcslen(const wchar_t *wstr)
{
	const wchar_t	*tmp;

	tmp = wstr;
	if (wstr == (void *)0)
		return (0);
	while (*tmp)
		++tmp;
	return ((size_t)(tmp - wstr));
}
