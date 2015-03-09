/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 06:41:19 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 06:41:19 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	isprint_base_test(int c)
{
	int		result;

	result = OK;
	if (isprint(c) != ft_isprint(c))
		result = debug_isprint(c);
	return (result);
}

static int	isprint_tests1(void)
{
	int		result;

	result = OK;
	if (isprint_base_test('m') == KO)
		result = KO;
	if (isprint_base_test(-1) == KO)
		result = KO;
	if (isprint_base_test('A') == KO)
		result = KO;
	if (isprint_base_test('Z') == KO)
		result = KO;
	if (isprint_base_test('3') == KO)
		result = KO;
	if (isprint_base_test('z') == KO)
		result = KO;
	if (isprint_base_test('\200') == KO)
		result = KO;
	return (result);
}

int			isprint_tests(void)
{
	if (isprint_tests1() == KO)
		return (KO);
	return (OK);
}
