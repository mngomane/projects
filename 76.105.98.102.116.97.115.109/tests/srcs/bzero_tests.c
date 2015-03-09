/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 01:24:35 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 01:24:35 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	bzero_base_test(char *str, size_t size, size_t len)
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
	bzero(str1, size);
	ft_bzero(str2, size);
	if (memcmp(str1, str2, len))
		result = debug_bzero(str1, str2);
	if (str != NULL)
	{
		free(str1);
		free(str2);
	}
	return (result);
}

static int	bzero_tests1(void)
{
	int		result;

	result = OK;
	if (bzero_base_test("tata", 5, strlen("tata")) == KO)
		result = KO;
	if (bzero_base_test("tata", 0, strlen("tata")) == KO)
		result = KO;
	if (bzero_base_test("tata", 10, strlen("tata")) == KO)
		result = KO;
	if (bzero_base_test("tata", 3, strlen("tata")) == KO)
		result = KO;
	if (bzero_base_test("tata", 200000, strlen("tata")) == KO)
		result = KO;
	return (result);
}

static int	bzero_tests2(void)
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
	if (bzero_base_test(str, 20, len) == KO)
		result = KO;
	free(str);
	return (result);
}

static int	bzero_tests3(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 5;
	str = (char *)malloc(sizeof(char) * len);
	if (bzero_base_test(str, 5, len) == KO)
		result = KO;
	if (bzero_base_test(str, 0, len) == KO)
		result = KO;
	if (bzero_base_test(str, 1, len) == KO)
		result = KO;
	free(str);
	return (result);
}

int			bzero_tests(void)
{
	if (bzero_tests1() == KO)
		return (KO);
	if (bzero_tests2() == KO)
		return (KO);
	if (bzero_tests3() == KO)
		return (KO);
	return (OK);
}
