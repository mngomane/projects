/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 03:34:35 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 03:34:35 by mngomane         ###   ########.fr       */
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

static int	strcat_base_test(char *str1, char *str2, size_t len)
{
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	int		result;

	result = OK;
	str3 = NULL;
	str4 = NULL;
	str5 = NULL;
	str6 = NULL;
	init_strings(str1, &str3, &str4);
	init_strings(str2, &str5, &str6);
	if (memcmp(strcat(str3, str5), ft_strcat(str4, str6), len))
		result = debug_strcat(str3, str5, str4, str6);
	free_strings(str1, &str3, &str4);
	free_strings(str2, &str5, &str6);
	return (result);
}

static int	strcat_tests1(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 10;
	str = (char *)malloc(sizeof(char) * len);
	str = strcpy(str, "titi");
	if (strcat_base_test(str, "eol", len) == KO)
		result = KO;
	free(str);
	str = (char *)malloc(sizeof(char) * len);
	str = strcpy(str, "tutu");
	if (strcat_base_test(str, "", len) == KO)
		result = KO;
	free(str);
	return (result);
}

int			strcat_tests(void)
{
	if (strcat_tests1() == KO)
		return (KO);
	return (OK);
}
