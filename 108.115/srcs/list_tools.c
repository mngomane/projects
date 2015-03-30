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

t_list			*ilst(char *dir_name, int (*cmp)(t_list *, t_list *))
{
	struct dirent	*dp;
	DIR				*dirp;
	t_list			*lst;
	char			*tmp;

	lst = (void *)0;
	dirp = opendir(dir_name);
	if (dirp == NULL)
	{
		tmp = (char *)ft_memalloc(sizeof(char) << 9);
		tmp = ft_strcat(tmp, BIN_NAME);
		tmp = ft_strcat(tmp, ": ");
		tmp = ft_strcat(tmp, dir_name);
		perror(tmp);
		free(tmp);
	}
	sort_lstadd(NULL, NULL, NULL);
	while (dirp && (dp = readdir(dirp)) != NULL)
	{
		tmp = (!ft_strcmp(dir_name, ".") ? "" : ft_strjoin(dir_name, "/"));
		sort_lstadd(&lst, ft_lstnew(new_file(tmp, dp->d_name), sizeof(t_file)), cmp);
	}
	(void)closedir(dirp);
	return (lst);
}
