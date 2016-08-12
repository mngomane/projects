/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstrings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 21:16:55 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/04 21:16:55 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	putpstr(t_pstring *pstring)
{
	if (pstring != NULL)
		write(1, pstring->start, (size_t)(pstring->end - pstring->start));
}

int		ft_pstrcmp(const char *s1, const char *e1, const char *s2, const char *e2)
{
	char	*iterator1;
	char	*iterator2;

	iterator1 = (char *)s1;
	iterator2 = (char *)s2;
	while (iterator1 != e1 && iterator2 != e2)
	{
		if (*iterator1 != *iterator2)
			return (1);
		++iterator1;
		++iterator2;
	}
	if ((iterator1 == e1 && iterator2 != e2) ||
		(iterator1 != e1 && iterator2 == e2))
		return (1);
	return (0);
}

char	*ft_pstrend(const char *str)
{
	char	*iterator;

	iterator = (char *)str;
	while (*iterator != '\0')
		++iterator;
	return (iterator);
}
