/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 03:02:43 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/14 03:02:43 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))) != (void *)0)
	{
		tmp->content = ft_memdup(content, content_size);
		tmp->content_size = (content ? content_size : 0);
		tmp->next = (void *)0;
	}
	return (tmp);
}
