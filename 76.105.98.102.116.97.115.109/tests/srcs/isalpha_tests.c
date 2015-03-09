/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islapha_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 05:40:40 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 05:40:40 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	isalpha_base_test(int c)
{
	int		result;

	result = OK;
	if (isalpha(c) != ft_isalpha(c))
		result = debug_isalpha(c);
	return (result);
}

static int	isalpha_tests1(void)
{
	int		result;

	result = OK;
	if (isalpha_base_test('5') == KO)
		result = KO;
	if (isalpha_base_test(-1) == KO)
		result = KO;
	if (isalpha_base_test('A') == KO)
		result = KO;
	if (isalpha_base_test('Z') == KO)
		result = KO;
	if (isalpha_base_test('a') == KO)
		result = KO;
	if (isalpha_base_test('z') == KO)
		result = KO;
	if (isalpha_base_test('\200') == KO)
		result = KO;
	return (result);
}

int			islapha_tests(void)
{
	if (isalpha_tests1() == KO)
		return (KO);
	return (OK);
}
