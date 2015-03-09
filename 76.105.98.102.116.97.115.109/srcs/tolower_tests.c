/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 06:59:24 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 06:59:24 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	tolower_base_test(int c)
{
	int		result;

	result = OK;
	if (tolower(c) != ft_tolower(c))
		result = debug_tolower(c);
	return (result);
}

static int	tolower_tests1(void)
{
	int		result;

	result = OK;
	if (tolower_base_test('m') == KO)
		result = KO;
	if (tolower_base_test(-1) == KO)
		result = KO;
	if (tolower_base_test('A') == KO)
		result = KO;
	if (tolower_base_test('Z') == KO)
		result = KO;
	if (tolower_base_test('3') == KO)
		result = KO;
	if (tolower_base_test('z') == KO)
		result = KO;
	if (tolower_base_test('\200') == KO)
		result = KO;
	return (result);
}

int			tolower_tests(void)
{
	if (tolower_tests1() == KO)
		return (KO);
	return (OK);
}
