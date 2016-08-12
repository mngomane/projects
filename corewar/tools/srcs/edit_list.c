/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 01:24:01 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/02 01:24:01 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"






#include <stdio.h>


void			link_param(struct s_parameter **p, char *start, char *end)
{
	struct s_parameter	*tmp;
	struct s_parameter	*save;

	save = NULL;
	if ((tmp = declare_s_parameter()) != NULL)
	{
		tmp->value = init_pstring(start, end);
		save = *p;
		while (*p && (*p)->next)
			*p = (*p)->next;
		if (*p)
			(*p)->next = tmp;
		else
			*p = tmp;
		if (save)
			*p = save;
	}
	else
		ft_putstr_fd("malloc in link_param failed [edit_list.c]\n", 2);
}

void			link_instruction(t_instruction **i, char *start, char *end)
{
	t_instruction	*tmp;
	t_instruction	*save;

	save = NULL;
	if ((tmp = declare_t_instruction()) != NULL)
	{
		tmp->content = init_pstring(start, end);
		save = *i;
		while (*i && (*i)->next)
			*i = (*i)->next;
		if (*i)
			(*i)->next = tmp;
		else
			*i = tmp;
		if (save)
			*i = save;
	}
	else
		ft_putstr_fd("malloc in add_inst failed [edit_list.c]\n", 2);
}
