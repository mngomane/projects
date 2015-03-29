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

static void		display_usage(void *flags)
{
	char		*copy;

	copy = (char *)flags;
	*copy = 0;
	ft_puterr(LS_USAGE);
}

static void		display_ok(void *flags)
{
	(void)flags;
	write(1, "OK!\n", 4);
}

static t_lut	*init_lookup_table(void)
{
	t_lut		*lookup;

	lookup = (t_lut *)ft_memalloc(sizeof(t_lut) << 3);
	lookup[0].key = "R";
	lookup[0].fct = display_ok;
	lookup[1].key = "l";
	lookup[1].fct = display_ok;
	lookup[2].key = "a";
	lookup[2].fct = display_ok;
	lookup[3].key = "r";
	lookup[3].fct = display_ok;
	lookup[4].key = "t";
	lookup[4].fct = display_ok;
	lookup[5].key = "?";
	lookup[5].fct = display_usage;
	return (lookup);
}

static int		get_options(int *ac, char ***av, void *flags)
{
	t_lut		*lookup;
	int			opti;
	int			c;
	int			i;

	opti = 1;
	lookup = init_lookup_table();
	c = ft_getopt(*ac, *av, "Rlart", &opti);
	while (c != -1 && c != '?')
	{
		i = 0;
		while (lookup[i].fct != (void *)0)
		{
			if (*((char *)lookup[i].key) == c)
				lookup[i].fct(flags);
			++i;
		}
		c = ft_getopt(*ac, *av, "Rlart", &opti);
	}
	*ac -= opti;
	av += opti;
	free(lookup);
	return (c);
}

int				main(int ac, char **av)
{
	char		flags;

	(void)ac, (void)av;
	flags = 0;
	if (get_options(&ac, &av, &flags) == '?')
		return (-1);
	return (0);
}
