/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 06:23:44 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/31 06:23:44 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	atoi_base_test(char *str)
{
	int		result;

	result = OK;
	if (atoi(str) != ft_atoi(str))
		result = debug_atoi(str);
	return (result);
}

static int	atoi_tests1(void)
{
	int		result;

	result = OK;
	if (atoi_base_test("") == KO)
		result = KO;
	if (atoi_base_test("123548") == KO)
		result = KO;
	if (atoi_base_test("-521547") == KO)
		result = KO;
	if (atoi_base_test("684684684684684") == KO)
		result = KO;
	if (atoi_base_test("    \t \t \t \f \v") == KO)
		result = KO;
	if (atoi_base_test("314PommedeTerre") == KO)
		result = KO;
	if (atoi_base_test("\n\n\n\n\n\n546tata") == KO)
		result = KO;
	if (atoi_base_test("512\t\t\t\t\t14") == KO)
		result = KO;
	return (result);
}

static int	atoi_tests2(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 20;
	str = (char *)malloc(sizeof(char) * len);
	str[0] = '1';
	str[1] = '2';
	str[2] = '3';
	str[3] = '4';
	str[13] = '7';
	if (atoi_base_test(str) == KO)
		result = KO;
	free(str);
	return (result);
}

static int	atoi_tests3(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 5;
	str = (char *)malloc(sizeof(char) * len);
	if (atoi_base_test(str) == KO)
		result = KO;
	free(str);
	return (result);
}

int			atoi_tests(void)
{
	if (atoi_tests1() == KO)
		return (KO);
	if (atoi_tests2() == KO)
		return (KO);
	if (atoi_tests3() == KO)
		return (KO);
	return (OK);
}
