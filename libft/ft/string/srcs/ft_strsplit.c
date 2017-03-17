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

#include "ft_string.h"

// char		**ft_strsplit(char const *s, char c)
// {
// 	char	**tab;
// 	size_t	len;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	len = ft_strlen(s);
// 	tab = (char **)malloc(sizeof(char *) * CEIL(len));
// 	while (s && *s && i < CEIL(len))
// 	{
// 		while (s && *s && *s == c)
// 			++s;
// 		tab[i] = (*s ? ft_strdup(s) : (void *)0);
// 		j = 0;
// 		while (s && *s && *s != c)
// 		{
// 			++j;
// 			++s;
// 		}
// 		if (*s)
// 			tab[i++][j] = '\0';
// 	}
// 	return (tab);
// }
