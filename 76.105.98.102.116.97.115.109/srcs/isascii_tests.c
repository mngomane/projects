/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 06:33:30 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 06:33:30 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	isascii_base_test(int c)
{
	int		result;

	result = OK;
	if (isascii(c) != ft_isascii(c))
		result = debug_isascii(c);
	return (result);
}

static int	isascii_tests1(void)
{
	int		result;

	result = OK;
	if (isascii_base_test('m') == KO)
		result = KO;
	if (isascii_base_test(-1) == KO)
		result = KO;
	if (isascii_base_test('A') == KO)
		result = KO;
	if (isascii_base_test('Z') == KO)
		result = KO;
	if (isascii_base_test('3') == KO)
		result = KO;
	if (isascii_base_test('z') == KO)
		result = KO;
	if (isascii_base_test('\200') == KO)
		result = KO;
	return (result);
}

int			isascii_tests(void)
{
	if (isascii_tests1() == KO)
		return (KO);
	return (OK);
}
