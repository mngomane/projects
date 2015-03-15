/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 15:28:28 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 17:41:22 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(int ac, char **av)
{
	t_list		*arg;
	t_opt		*op;

	arg = (void *)0;
	op = (void *)0;
	if (!init_main(&arg, &op, ac))
		return (-1);
	body_main(arg, op, ac, av);
	free_opt(&op);
	return (0);
}
