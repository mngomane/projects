/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:36:49 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 23:36:49 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

t_file			*new_file(void *path, void *name, u_char flags)
{
	t_file		*file;

	if ((file = (t_file *)ft_memalloc(sizeof(t_file))) != (void *)0)
	{
		if ((file->stat = (t_stat *)ft_memalloc(sizeof(t_stat))))
		{
			if (!F_LONG(flags) ||
				(lstat(ft_strjoin(path, name), file->stat) == -1))
			{
				if (stat(ft_strjoin(path, name), file->stat) == -1)
				{
					free(file->stat);
					file->stat = (void *)0;
					ft_puterr(BIN_NAME);
					ft_puterr(": ");
					perror(name);
				}
			}
		}
		file->name = ft_strdup(name);
	}
	return (file);
}
