/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 23:42:32 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/13 23:42:32 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	index;

	index = 0;
	tab = (char **)malloc(sizeof(char *) * MAX_SPLIT);
	ft_bzero(tab, MAX_SPLIT * sizeof(char *));
	while (s && *s && index++ < MAX_SPLIT)
	{
		while (s && *s == c)
			++s;
		tab[index] = ft_strdup(s);
		while (s && *s != c)
		{
			++s;
			++(tab[index]);
		}
		*(tab[index]) = 0;
	}
	return (tab);
}
