/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illegal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 20:07:24 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 19:20:19 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

int			valid_op(t_opt **op)
{
	t_opt	*save;
	int		v;

	save = *op;
	v = 1;
	while (*op != NULL && v == 1)
	{
		v = 0;
		if (!ft_strcmp((*op)->oname, "-l"))
			v = 1;
		if (!ft_strcmp((*op)->oname, "-a"))
			v = 1;
		if (!ft_strcmp((*op)->oname, "-1"))
			v = 1;
		if (!ft_strcmp((*op)->oname, "-1a"))
			v = 1;
		if (v == 1)
			*op = (*op)->next;
	}
	if (v)
	{
		*op = save;
		return (1);
	}
	return (0);
}

void		whatelse(char *name)
{
	write(1, ILLEGAL, sizeof(ILLEGAL));
	ft_putendl(name);
}
