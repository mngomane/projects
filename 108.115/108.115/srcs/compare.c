/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:25:24 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 23:25:24 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			lexical_cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp((char *)(LVALUE(t_file *, lst1)->name),
			(char *)(LVALUE(t_file *, lst2)->name)) < 0);
}
