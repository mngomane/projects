/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:37:54 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 23:37:54 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			del_lst(void *file, size_t size)
{
	size = 0;
	free(((t_file *)file)->name);
	free(((t_file *)file)->link);
	free(((t_file *)file)->stat);
	free(file);
}
