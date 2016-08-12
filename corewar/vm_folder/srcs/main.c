/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 23:36:05 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/19 23:36:05 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_usage_message(void)
{
	ft_putstr("Usage: ./corewar [-d N -s N -v N | -b --stealth | -n");
	ft_putstr(" --stealth] [-a] <champion1.cor> <...>\n    -a        :");
	ft_putstr(" Prints output from \"aff\" (Default is to hide it)\n####");
	ft_putstr(" TEXT OUTPUT MODE #########################################");
	ft_putstr("#################\n    -d N      : Dumps memory after N");
	ft_putstr(" cycles then exits\n    -s N      : Runs N cycles, dumps");
	ft_putstr(" memory, pauses, then repeats\n    -v N      : Verbosity ");
	ft_putstr("levels, can be added together to enable several\n         ");
	ft_putstr("       - 0 : Show only essentials\n                - 1 : ");
	ft_putstr("Show lives\n                - 2 : Show cycles\n            ");
	ft_putstr("    - 4 : Show operations (Params are NOT litteral ...)\n   ");
	ft_putstr("             - 8 : Show deaths\n#### BINARY OUTPUT MODE #####");
	ft_putstr("###################################################\n    -b   ");
	ft_putstr("     : Binary output mode for corewar.42.fr\n    --stealth : ");
	ft_putstr("Hides the real contents of the memory\n#### NCURSES OUTPUT ");
	ft_putstr("MODE #######################################################\n");
	ft_putstr("    -n        : Ncurses output mode\n    --stealth : Hides the");
	ft_putstr(" real contents of the memory\n################################");
	ft_putstr("################################################\n");
}

int			main(int ac, char **av)
{
	if (ac == 1)
		print_usage_message();
	else
		ft_putstr(av[1]);
	return (0);
}
