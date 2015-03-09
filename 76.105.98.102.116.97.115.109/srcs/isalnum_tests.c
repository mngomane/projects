/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 06:20:10 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 06:20:10 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	isalnum_base_test(int c)
{
	int		result;

	result = OK;
	if (isalnum(c) != ft_isalnum(c))
		result = debug_isalnum(c);
	return (result);
}

static int	isalnum_tests1(void)
{
	int		result;

	result = OK;
	if (isalnum_base_test('m') == KO)
		result = KO;
	if (isalnum_base_test(-1) == KO)
		result = KO;
	if (isalnum_base_test('A') == KO)
		result = KO;
	if (isalnum_base_test('Z') == KO)
		result = KO;
	if (isalnum_base_test('3') == KO)
		result = KO;
	if (isalnum_base_test('z') == KO)
		result = KO;
	if (isalnum_base_test('\200') == KO)
		result = KO;
	return (result);
}

int			isalnum_tests(void)
{
	if (isalnum_tests1() == KO)
		return (KO);
	return (OK);
}
