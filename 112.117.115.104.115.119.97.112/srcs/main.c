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

static int		variations(t_stack *list)
{
	int		sign;
	int		i;
	off_t	cmp;

	i = 1;
	if (list->size == 0)
		return (0);
	cmp = (off_t)(list->value)[i] - (off_t)(list->value)[i - 1];
	sign = (cmp >= 0 ? 1 : -1);
	while (sign * cmp >= 0 && i < (int)list->size)
	{
		++i;
		cmp = (off_t)(list->value)[i] - (off_t)(list->value)[i - 1];
	}
	return (sign * i);
}

static void		ft_filltab(t_stack *l_a, char **av)
{
	size_t		i;

	i = 1;
	while (i < l_a->size + 1)
	{
		(l_a->value)[i - 1] = ft_atoi(av[i]);
		++i;
	}
}

static int8_t	push_quit(int8_t error)
{
	if (error != OK)
	{
		ft_puterr(I_ERROR);
		return (error);
	}
	return (OK);
}

int				main(int ac, char **av)
{
	t_stack		l_a;
	t_stack		l_b;
	int8_t		option;

	ft_bzero(&l_a, sizeof(t_stack));
	ft_bzero(&l_b, sizeof(t_stack));
	option = ((ac > 1) ? get_option(av) : NONE);
	if (option == DEBUG && ac--)
		++av;
	if (push_quit(error_found(ac, av)) != OK)
		return (-1);
	l_a.value = (int *)malloc(sizeof(int) * (size_t)(ac - 1));
	l_a.size = (size_t)(ac - 1);
	ft_filltab(&l_a, av);
	if (variations(&l_a) != (ac - 1) && ac != 2)
		bub_swap(&l_a, &l_b);
	if (option == DEBUG)
		display_stacks(l_a, l_b);
	return (0);
}
