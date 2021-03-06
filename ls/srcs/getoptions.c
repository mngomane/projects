/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getoptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 11:30:19 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 11:30:19 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		display_usage(void *flags, void *i)
{
	char		*copy;
	int			*index;

	copy = (char *)flags;
	index = (int *)i;
	*copy = 0;
	*index = *index;
	ft_puterr(BIN_USAGE);
}

static void		set_flag(void *flags, void *i)
{
	u_char		bit;
	u_char		mask;
	u_char		*copy;

	copy = (u_char *)flags;
	bit = (u_char)(*(int *)i);
	mask = (u_char)(1 << bit);
	*copy |= mask;
}

static t_lut	*init_lookup_table(void)
{
	t_lut		*lookup;

	if ((lookup = (t_lut *)ft_memalloc(sizeof(t_lut) << 3)))
	{
		lookup[0].key = "R";
		lookup[0].fct = set_flag;
		lookup[1].key = "a";
		lookup[1].fct = set_flag;
		lookup[2].key = "l";
		lookup[2].fct = set_flag;
		lookup[3].key = "r";
		lookup[3].fct = set_flag;
		lookup[4].key = "t";
		lookup[4].fct = set_flag;
		lookup[5].key = "?";
		lookup[5].fct = display_usage;
	}
	return (lookup);
}

int				get_options(int *ac, char ***av, void *flags)
{
	t_lut		*lookup;
	int			opt_i;
	int			c;
	int			i;

	c = 0;
	opt_i = 1;
	lookup = init_lookup_table();
	while (lookup && c != -1 && c != '?')
	{
		i = 0;
		c = ft_getopt(*ac, *av, "Ralrt", &opt_i);
		while (lookup[i].fct != (void *)0)
		{
			if (*((char *)lookup[i].key) == c)
				lookup[i].fct(flags, &i);
			++i;
		}
	}
	*ac -= opt_i;
	*av += opt_i;
	free(lookup);
	return (c);
}
