/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 00:42:56 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/30 00:42:56 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	init_strings(char *str, char **str1, char **str2)
{
	if (str != NULL)
	{
		*str1 = strdup(str);
		*str2 = strdup(str);
	}
	else
	{
		*str1 = NULL;
		*str2 = NULL;
	}
	++str1;
	++str2;
	--str1;
	--str2;
}

static void	free_strings(char *str, char **str1, char **str2)
{
	if (str != NULL)
	{
		free(*str1);
		free(*str2);
	}
}

static int	memcpy_base_test(char *str1, char *str2, size_t size, size_t len)
{
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	int		result;

	len++;
	--len;
	++size;
	--size;
	result = OK;
	str3 = NULL;
	str4 = NULL;
	str5 = NULL;
	str6 = NULL;
	init_strings(str1, &str3, &str4);
	init_strings(str2, &str5, &str6);
	if (strcmp(memcpy(str3, str5, size), ft_memcpy(str4, str6, size)))
		result = debug_memcpy(str3, str4);
	if (strcmp(str3, str4))
		result = debug_memcpy(str3, str4);
	free_strings(str1, &str3, &str4);
	free_strings(str2, &str5, &str6);
	return (result);
}

static int	memcpy_tests1(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 5;
	str = (char *)malloc(sizeof(char) * len);
	if (memcpy_base_test(str, "tatatototititutu", 5, len) == KO)
		result = KO;
	if (memcpy_base_test(str, "", 5, len) == KO)
		result = KO;
	if (memcpy_base_test(str, "", 0, len) == KO)
		result = KO;
	free(str);
	str = (char *)malloc(sizeof(char) * 20);
	str[0] = 't';
	str[1] = 'i';
	str[2] = 't';
	str[3] = 'i';
	str[4] = '\0';
	str[13] = 'm';
	if (memcpy_base_test(str, "tutu", 20, 20) == KO)
		result = KO;
	free(str);
	return (result);
}

int			memcpy_tests(void)
{
	if (memcpy_tests1() == KO)
		return (KO);
	return (OK);
}
