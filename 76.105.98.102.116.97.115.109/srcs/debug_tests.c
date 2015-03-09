/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 04:22:35 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 04:22:35 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	debug_bzero(char *str1, char *str2)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:bzero]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	ft_puts("");
	ft_putstr(debug_string);
	ft_putstr(system_string);
	ft_puts(str1);
	ft_putstr(debug_string);
	ft_putstr(your_string);
	ft_puts(str2);
	return (KO);
}

int	debug_strcat(char *str1, char *str2, char *str3, char *str4)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:strcat]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	ft_puts("");
	ft_putstr(debug_string);
	ft_putstr(system_string);
	ft_puts(strcat(str1, str2));
	ft_putstr(debug_string);
	ft_putstr(your_string);
	ft_puts(ft_strcat(str3, str4));
	return (KO);
}

int	debug_toupper(int c)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:toupper]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	ft_puts("");
	ft_putstr(debug_string);
	ft_putstr(system_string);
	printf("%d\n", toupper(c));
	ft_putstr(debug_string);
	ft_putstr(your_string);
	printf("%d\n", ft_toupper(c));
	return (KO);
}

int	debug_tolower(int c)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:toupper]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	ft_puts("");
	ft_putstr(debug_string);
	ft_putstr(system_string);
	printf("%d\n", tolower(c));
	ft_putstr(debug_string);
	ft_putstr(your_string);
	printf("%d\n", ft_tolower(c));
	return (KO);
}
