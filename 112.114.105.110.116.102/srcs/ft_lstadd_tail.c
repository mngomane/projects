/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 03:59:39 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 03:59:39 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_tail(t_list **alst, t_list *new)
{
	t_list	*save;

	save = *alst;
	while (*alst && (*alst)->next)
		*alst = (*alst)->next;
	if (*alst)
	{
		(*alst)->next = new;
		if (new)
			(*alst)->next->next = (void *)0;
		*alst = save;
	}
	else
		*alst = new;
}
