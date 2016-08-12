/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 03:39:12 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 03:39:12 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	tmp = (void *)0;
	while (*alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&tmp, del);
	}
}
