/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 08:25:16 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/02 08:25:16 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	puts_base_test(char *str)
{
	int		result;
	FILE	*save_stdout_stream;

	result = OK;
	save_stdout_stream = stdout;
	fclose (stdout);
	stdout = fopen ("system.test", "w");
	puts(str);
	fclose (stdout);
	stdout = fopen ("your.test", "w");
	ft_puts(str);
	fclose (stdout);
	stdout = save_stdout_stream;
	result = compare_files("system.test", "your.test");
	unlink("system.test");
	unlink("your.test");
	return (result);
}

static int	puts_tests1(void)
{
	int		result;

	result = OK;
	if (puts_base_test("tata") == KO)
		result = KO;
	if (puts_base_test("123456tata/") == KO)
		result = KO;
	if (puts_base_test("") == KO)
		result = KO;
	if (puts_base_test(NULL) == KO)
		result = KO;
	if (puts_base_test("1245412\0fsdf3") == KO)
		result = KO;
	return (result);
}

static int	puts_tests2(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 20;
	str = (char *)malloc(sizeof(char) * len);
	str[0] = 0x09;
	str[1] = 0x0c;
	str[2] = 0x1c;
	str[3] = 0x18;
	str[4] = '\0';
	str[13] = 'm';
	if (puts_base_test(str) == KO)
		result = KO;
	free(str);
	return (result);
}

static int	puts_tests3(void)
{
	char	*str;
	int		result;
	size_t	len;

	result = OK;
	len = 5;
	str = (char *)malloc(sizeof(char) * len);
	if (puts_base_test(str) == KO)
		result = KO;
	if (puts_base_test(str) == KO)
		result = KO;
	if (puts_base_test(str) == KO)
		result = KO;
	free(str);
	return (result);
}

int		puts_tests(void)
{
	if (puts_tests1() == KO)
		return (KO);
	if (puts_tests2() == KO)
		return (KO);
	if (puts_tests3() == KO)
		return (KO);
	return (OK);
}
