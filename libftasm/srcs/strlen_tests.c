/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 07:20:24 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 07:20:24 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	strlen_base_test(char *str)
{
	int		result;

	result = OK;
	if (strlen(str) != ft_strlen(str))
		result = debug_strlen(str);
	return (result);
}

static int	strlen_tests1(void)
{
	int		result;

	result = OK;
	if (strlen_base_test("") == KO)
		result = KO;
	if (strlen_base_test("000000") == KO)
		result = KO;
	if (strlen_base_test("A") == KO)
		result = KO;
	if (strlen_base_test("                 ") == KO)
		result = KO;
	if (strlen_base_test("pomme") == KO)
		result = KO;
	return (result);
}

int			strlen_tests(void)
{
	if (strlen_tests1() == KO)
		return (KO);
	return (OK);
}
