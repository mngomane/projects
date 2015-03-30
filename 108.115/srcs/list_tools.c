/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:34:27 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/29 23:34:27 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ilst(char *name, int (*cmp)(t_list *, t_list *), u_char flags)
{
	struct dirent	*dp;
	DIR				*dirp;
	t_list			*lst;
	char			*tmp;

	lst = (void *)0;
	dirp = opendir(name);
	if (dirp == (void *)0)
	{
		tmp = (char *)ft_memalloc(sizeof(char) << 9);
		tmp = ft_strcat(tmp, BIN_NAME": ");
		tmp = ft_strcat(tmp, name);
		perror(tmp);
		free(tmp);
		return (lst);
	}
	sort_lstadd((void *)0, (void *)0, (void *)0);
	while (dirp && (dp = readdir(dirp)) != (void *)0)
	{
		tmp = (!ft_strcmp(name, ".") ? "" : ft_strjoin(name, "/"));
		sort_lstadd(&lst, ft_lstnew(new_file(tmp, dp->d_name, flags),
					sizeof(t_file)), cmp);
	}
	(void)closedir(dirp);
	return (lst);
}
