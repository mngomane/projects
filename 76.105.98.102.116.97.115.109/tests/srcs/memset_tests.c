/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 07:36:14 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 07:36:14 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	memset_base_test(char *str, int c, size_t size, size_t len)
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
	if (memcmp(memset(str1, c, size), ft_memset(str2, c, size), len))
		result = debug_memset(str1, str2);
	if (memcmp(str1, str2, len))
		result = debug_memset(str1, str2);
	if (str != NULL)
		free(str1);
	return (result);
}

static int	memset_tests1(void)
{
	int		result;

	result = OK;
	if (memset_base_test("tata", '\0', 5, strlen("tata")) == KO)
		result = KO;
	if (memset_base_test("tata", '\0', 0, strlen("tata")) == KO)
		result = KO;
	if (memset_base_test("tata", '\0', 10, strlen("tata")) == KO)
		result = KO;
	if (memset_base_test("tata", '\0', 3, strlen("tata")) == KO)
		result = KO;
	if (memset_base_test("tata", '\0', 200000, strlen("tata")) == KO)
		result = KO;
	return (result);
}

static int	memset_tests2(void)
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
	if (memset_base_test(str, '\0', 20, len) == KO)
		result = KO;
	free(str);
	return (result);
}

static int	memset_tests3(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 5;
	str = (char *)malloc(sizeof(char) * len);
	if (memset_base_test(str, '\0', 5, len) == KO)
		result = KO;
	if (memset_base_test(str, 'a', 0, len) == KO)
		result = KO;
	if (memset_base_test(str, 3, 1, len) == KO)
		result = KO;
	free(str);
	return (result);
}

int			memset_tests(void)
{
	if (memset_tests1() == KO)
		return (KO);
	if (memset_tests2() == KO)
		return (KO);
	if (memset_tests3() == KO)
		return (KO);
	return (OK);
}
