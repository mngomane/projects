/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 00:46:39 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/24 00:46:39 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	do_son(int pfd[2], int (*tests)(void))
{
	char	result[2];

	close(pfd[IN]);
	result[0] = (char)(tests() + '0');
	result[1] = '\0';
	write(pfd[OUT], result, 2);
	close(pfd[OUT]);
}

static void	do_father(pid_t pid, int pfd[2])
{
	int		status;
	pid_t	son_pid;
	char	buf[2];
	int		result;

	close(pfd[OUT]);
	status = pid;
	result = -1;
	buf[0] = '\0';
	buf[1] = '\0';
	son_pid = waitpid(pid, &status, WUNTRACED);
	read(pfd[IN], buf, 2);
	close(pfd[IN]);
	if (WIFEXITED(status))
		result = atoi(buf);
	if (result == KO)
		ft_puts("> [KO]");
	else if (result == OK)
		ft_puts(": [OK]");
	else if (result == -1)
		ft_puts("> [ERROR]");
	kill(son_pid, SIGKILL);
}

static void	do_tests(char *name, int (*tests)(void))
{
	pid_t	pid;
	int		pfd[2];

	pfd[IN] = -1;
	pfd[OUT] = -1;
	if (pipe(pfd) == -1)
		ft_puts("\033[31;1mInternal Error!\033[0m");
	write(1, name, strlen(name));
	if ((pid = fork()) == -1)
		ft_puts("\033[31;1mInternal Error!\033[0m");
	if (!pid)
	{
		do_son(pfd, tests);
		_exit(0);
	}
	else if (pid != -1)
		do_father(pid, pfd);
}

int			main(void)
{
	do_tests("ft_atoi", atoi_tests);
	do_tests("ft_bzero", bzero_tests);
	do_tests("ft_cat", cat_tests);
	do_tests("ft_isalnum", isalnum_tests);
	do_tests("ft_isalpha", islapha_tests);
	do_tests("ft_isascii", isascii_tests);
	do_tests("ft_isdigit", isdigit_tests);
	do_tests("ft_isprint", isprint_tests);
	do_tests("ft_memcpy", memcpy_tests);
	do_tests("ft_memset", memset_tests);
	do_tests("ft_puts", puts_tests);
	do_tests("ft_strcat", strcat_tests);
	do_tests("ft_strdup", strdup_tests);
	do_tests("ft_strlen", strlen_tests);
	do_tests("ft_tolower", tolower_tests);
	do_tests("ft_toupper", toupper_tests);
	return (0);
}
