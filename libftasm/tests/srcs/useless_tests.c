/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 05:38:50 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 05:38:50 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	debug_isalpha(int c)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:isalpha]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	puts("");
	write(1, debug_string, strlen(debug_string));
	write(1, system_string, strlen(system_string));
	printf("%d\n", isalpha(c));
	write(1, debug_string, strlen(debug_string));
	write(1, your_string, strlen(your_string));
	printf("%d\n", ft_isalpha(c));
	return (KO);
}

int	debug_isdigit(int c)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:isdigit]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	puts("");
	write(1, debug_string, strlen(debug_string));
	write(1, system_string, strlen(system_string));
	printf("%d\n", isdigit(c));
	write(1, debug_string, strlen(debug_string));
	write(1, your_string, strlen(your_string));
	printf("%d\n", ft_isdigit(c));
	return (KO);
}

int	debug_isalnum(int c)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:isalnum]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	puts("");
	write(1, debug_string, strlen(debug_string));
	write(1, system_string, strlen(system_string));
	printf("%d\n", isalnum(c));
	write(1, debug_string, strlen(debug_string));
	write(1, your_string, strlen(your_string));
	printf("%d\n", ft_isalnum(c));
	return (KO);
}

int	debug_isascii(int c)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:isascii]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	puts("");
	write(1, debug_string, strlen(debug_string));
	write(1, system_string, strlen(system_string));
	printf("%d\n", isascii(c));
	write(1, debug_string, strlen(debug_string));
	write(1, your_string, strlen(your_string));
	printf("%d\n", ft_isascii(c));
	return (KO);
}

int	debug_isprint(int c)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:isprint]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	puts("");
	write(1, debug_string, strlen(debug_string));
	write(1, system_string, strlen(system_string));
	printf("%d\n", isprint(c));
	write(1, debug_string, strlen(debug_string));
	write(1, your_string, strlen(your_string));
	printf("%d\n", ft_isprint(c));
	return (KO);
}
