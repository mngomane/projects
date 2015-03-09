/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tests_part_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 07:15:25 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/29 07:15:25 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	debug_strlen(char *str)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:strlen]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	ft_puts("");
	ft_putstr(debug_string);
	ft_putstr(system_string);
	printf("%zu\n", strlen(str));
	ft_putstr(debug_string);
	ft_putstr(your_string);
	printf("%zu\n", ft_strlen(str));
	return (KO);
}

int	debug_memset(char *str1, char *str2)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:memset]\033[0m ";
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

int	debug_memcpy(char *str1, char *str2)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:memcpy]\033[0m ";
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

int	debug_strdup(char *str1, char *str2)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:strdup]\033[0m ";
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
