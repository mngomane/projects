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

void	sort_lstadd(t_list **root, t_list **end, t_list *new, int PROTO_CMP)
{
	if (cmp(new, *root))
		ft_lstadd(root, new);
	else if (!cmp(new, *end) || !(*root)->next)
	{
		(!cmp(new, *end) ? *end : *root)->next = new;
		*end = new;
	}
	else
		sort_lstadd(&(*root)->next, end, new, cmp);
}
