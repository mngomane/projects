/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 20:22:23 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/02 20:22:23 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	cat_base_test(char *str)
{
	FILE	*save_stdout_stream;
	int		ret_open;
	int		result;

	result = OK;
	ret_open = -1;
	ret_open = open(str, O_RDWR, 0777);
	save_stdout_stream = stdout;
	fclose (stdout);
	stdout = fopen ("your.test", "w");
	ft_cat(ret_open);
	stdout = save_stdout_stream;
	result = compare_files(str, "your.test");
	unlink("your.test");
	return (result);
}

static int	cat_tests1(void)
{
	int		result;
	int		ret_open;

	ret_open = -1;
	result = OK;
	if (cat_base_test("Makefile") == KO)
		result = KO;
	ret_open = open("srcs/files_test/test1",
		O_RDWR | O_CREAT | O_TRUNC, 0777);
	ft_putchar_fd('m', ret_open);
	close(ret_open);
	if (cat_base_test("srcs/files_test/test1") == KO)
		result = KO;
	unlink("srcs/files_test/test1");
	return (result);
}

static int	cat_tests2(void)
{
	int		result;
	int		ret_open;

	ret_open = -1;
	result = OK;
	ret_open = open("srcs/files_test/test2", O_RDWR | O_CREAT, 0777);
	ft_putchar_fd('\0', ret_open);
	ft_putchar_fd('a', ret_open);
	close(ret_open);
	if (cat_base_test("srcs/files_test/test2") == KO)
		result = KO;
	unlink("srcs/files_test/test2");
	ret_open = open("srcs/files_test/test3", O_RDWR | O_CREAT, 0777);
	ft_putchar_fd(0x07, ret_open);
	close(ret_open);
	if (cat_base_test("srcs/files_test/test3") == KO)
		result = KO;
	unlink("srcs/files_test/test3");
	return (result);
}

int			cat_tests(void)
{
	if (cat_tests1() == KO)
		return (KO);
	if (cat_tests2() == KO)
		return (KO);
	return (OK);
}
