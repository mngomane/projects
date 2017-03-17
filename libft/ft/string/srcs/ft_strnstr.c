/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:25:52 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:52 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// char		*ft_strnstr(const char *s1, const char *s2, size_t n)
// {
// 	char	*occ;
// 	size_t	index;

// 	occ = (char *)s1;
// 	index = 0;
// 	if (*s2 == '\0')
// 		return ((char *)s1);
// 	while (*occ != '\0' && s2[index] != '\0' && (size_t)(occ - (char *)s1) < n)
// 	{
// 		if (*occ == s2[index])
// 			++index;
// 		else
// 		{
// 			occ -= index;
// 			index = 0;
// 		}
// 		++occ;
// 	}
// 	if (s2[index] == 0)
// 		return (occ - index);
// 	return (NULL);
// }
