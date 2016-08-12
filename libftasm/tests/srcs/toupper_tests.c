/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 06:51:21 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 06:51:21 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	toupper_base_test(int c)
{
	int		result;

	result = OK;
	if (toupper(c) != ft_toupper(c))
		result = debug_toupper(c);
	return (result);
}

static int	toupper_tests1(void)
{
	int		result;

	result = OK;
	if (toupper_base_test('m') == KO)
		result = KO;
	if (toupper_base_test(-1) == KO)
		result = KO;
	if (toupper_base_test('A') == KO)
		result = KO;
	if (toupper_base_test('Z') == KO)
		result = KO;
	if (toupper_base_test('3') == KO)
		result = KO;
	if (toupper_base_test('z') == KO)
		result = KO;
	if (toupper_base_test('\200') == KO)
		result = KO;
	return (result);
}

int			toupper_tests(void)
{
	if (toupper_tests1() == KO)
		return (KO);
	return (OK);
}
