/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 13:07:02 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/28 13:07:02 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	sort_lstadd(t_list **root, t_list *new, int (*cmp)(t_list *, t_list *))
{
	static t_list	*end;

	end = (root ? end : (void *)0);
	if (!new || !root)
		return ;
	if (!*root || cmp(new, *root))
		ft_lstadd(root, new);
	else if ((end && !cmp(new, end)) || !(*root)->next)
	{
		((end && !cmp(new, end)) ? end : *root)->next = new;
		end = new;
	}
	else
		sort_lstadd(&(*root)->next, new, cmp);
}
