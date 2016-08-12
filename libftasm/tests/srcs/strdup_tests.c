/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 07:34:34 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/30 07:34:34 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	strdup_base_test(char *str)
{
	char	*str1;
	char	*str2;
	int		result;

	result = OK;
	if (str != NULL)
	{
		str1 = strdup(str);
		str2 = strdup(str);
	}
	else
	{
		str1 = NULL;
		str2 = NULL;
	}
	if (strcmp(str1, str2))
		result = debug_strdup(str1, str2);
	if (str != NULL)
	{
		free(str1);
		free(str2);
	}
	return (result);
}

static int	strdup_tests1(void)
{
	int		result;

	result = OK;
	if (strdup_base_test("tata") == KO)
		result = KO;
	if (strdup_base_test("") == KO)
		result = KO;
	if (strdup_base_test("c") == KO)
		result = KO;
	if (strdup_base_test("ashufdsdgsdf") == KO)
		result = KO;
	if (strdup_base_test("\0\0\0\0") == KO)
		result = KO;
	return (result);
}

static int	strdup_tests2(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 20;
	str = (char *)malloc(sizeof(char) * len);
	str[0] = 't';
	str[1] = 'o';
	str[2] = 't';
	str[3] = 'o';
	str[4] = '\0';
	str[13] = 'm';
	if (strdup_base_test(str) == KO)
		result = KO;
	free(str);
	return (result);
}

static int	strdup_tests3(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 5;
	str = (char *)malloc(sizeof(char) * len);
	if (strdup_base_test(str) == KO)
		result = KO;
	free(str);
	return (result);
}

int			strdup_tests(void)
{
	if (strdup_tests1() == KO)
		return (KO);
	if (strdup_tests2() == KO)
		return (KO);
	if (strdup_tests3() == KO)
		return (KO);
	return (OK);
}
