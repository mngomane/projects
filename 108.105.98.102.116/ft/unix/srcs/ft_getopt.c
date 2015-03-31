/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 09:25:41 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/27 09:25:41 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unix.h"

static int		opt_error(const char *arg, const char *msg, const int c)
{
	ft_puterr(arg);
	ft_puterr(msg);
	write(2, &c, 1);
	write(2, "\n", 1);
	return ('?');
}

static int		syntax_error(int ac, char *const *av, int *opti)
{
	if (*opti >= ac || av[*opti][0] != '-' || av[*opti][1] == '\0')
		return (-1);
	else if (ft_strcmp(av[*opti], "--") == 0)
	{
		(*opti)++;
		return (-1);
	}
	return (0);
}

static int		illegal_opt(char *const *av, int *opti, int *sp, int c)
{
	if (av[*opti][++(*sp)] == '\0')
	{
		(*opti)++;
		*sp = 1;
	}
	return (opt_error(av[0], ": illegal option -- ", c));
}

int				ft_getopt(int ac, char *const *av, const char *opts, int *opti)
{
	static int	sp = 1;
	int			c;
	char		*cp;

	if (sp == 1)
		if (syntax_error(ac, av, opti) == -1)
			return (-1);
	c = av[*opti][sp];
	if (c == ':' || (cp = ft_strchr(opts, c)) == (void *)0)
		return (illegal_opt(av, opti, &sp, c));
	if (*++cp == ':')
	{
		if (av[*opti][sp + 1] != '\0' && ++*opti >= ac)
		{
			sp = 1;
			return (opt_error(av[0], ": option requires an argument -- ", c));
		}
		sp = 1;
	}
	else if (av[*opti][++sp] == '\0')
	{
		sp = 1;
		(*opti)++;
	}
	return (c);
}
