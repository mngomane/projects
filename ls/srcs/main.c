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

	flags = 0;
	if (get_options(&ac, &av, &flags) == '?')
		return (-1);
	fdisplay(ac, av, ".", flags);
	return (0);
}
