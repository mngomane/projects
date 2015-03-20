/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 23:14:37 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/09 23:14:37 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list		l_a;
	t_list		l_b;
	t_index		tmp;
	t_option	option;
	size_t		i;

	option = ((ac > 1) ? get_swap_option(av) : NONE);
	if (option == DEBUG)
	{
		--ac;
		++av;
	}
	if (push_quit(error_found(ac, av)) != OK)
		return (-1);
	ft_varinit2(&l_a, &l_b, &i, &ac);
	ft_filltab(&l_a, &i, av);
	if (ft_var(l_a) != (ac - 1) && ac != 2)
	{
		ft_swap1(&l_a, &l_b, &i, &tmp);
		ft_swap2(&l_a, &l_b);
	}
	if (option == DEBUG)
		display_stacks(l_a, l_b);
	return (0);
}
