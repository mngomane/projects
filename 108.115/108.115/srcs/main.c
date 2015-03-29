/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 23:36:00 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/26 23:36:00 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(int ac, char **av)
{
	u_char		flags;

	(void)ac, (void)av;
	flags = 0;
	if (get_options(&ac, &av, &flags) == '?')
		return (-1);
	if (flags & 0x01)
		ft_putendl("flag R set!!!!");
	if (flags & 0x02)
		ft_putendl("flag a set!!!!");
	if (flags & 0x04)
		ft_putendl("flag l set!!!!");
	if (flags & 0x08)
		ft_putendl("flag r set!!!!");
	if (flags & 0x10)
		ft_putendl("flag t set!!!!");
	return (0);
}
