/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 06:05:00 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 06:05:00 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	isdigit_base_test(int c)
{
	int		result;

	result = OK;
	if (isdigit(c) != ft_isdigit(c))
		result = debug_isdigit(c);
	return (result);
}

static int	isdigit_tests1(void)
{
	int		result;

	result = OK;
	if (isdigit_base_test('m') == KO)
		result = KO;
	if (isdigit_base_test(-1) == KO)
		result = KO;
	if (isdigit_base_test('A') == KO)
		result = KO;
	if (isdigit_base_test('Z') == KO)
		result = KO;
	if (isdigit_base_test('3') == KO)
		result = KO;
	if (isdigit_base_test('z') == KO)
		result = KO;
	if (isdigit_base_test('\200') == KO)
		result = KO;
	return (result);
}

int			isdigit_tests(void)
{
	if (isdigit_tests1() == KO)
		return (KO);
	return (OK);
}
