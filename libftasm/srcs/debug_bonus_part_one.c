/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus_part_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 01:24:31 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/31 01:24:31 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	debug_atoi(char *str)
{
	char	*debug_string;
	char	*your_string;
	char	*system_string;

	debug_string = "\033[33;1m[Debug:atoi]\033[0m ";
	system_string = "System: ";
	your_string = "Yours: ";
	ft_puts("");
	ft_putstr(debug_string);
	ft_putstr(system_string);
	printf("%d\n", atoi(str));
	ft_putstr(debug_string);
	ft_putstr(your_string);
	printf("%d\n", ft_atoi(str));
	return (KO);
}
