/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 23:36:00 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/26 23:36:00 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


#include <stdio.h>

static t_file	*new_file(void *path, void *name)
{
	t_file		*file;

	(void)path;
	if ((file = (t_file *)ft_memalloc(sizeof(t_file))) != (void *)0)
	{
		/*file->path = ft_strdup(path);*/
		file->name = ft_strdup(name);
	}
	return (file);
}

static void		del_lstf(void *file, size_t size)
{
	size = 0;
	free(((t_file *)file)->dirp);
	free(((t_file *)file)->path);
	free(((t_file *)file)->name);
	/*free(((t_file *)file)->path);*/
	free(file);
}

static void		print_list(t_list *lst)
{
	while (lst)
	{
		ft_putendl((char *)(LVALUE(t_file *, lst)->name));
		lst = lst->next;
	}
}

static int		cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp((char *)(LVALUE(t_file *, lst1)->name),
			(char *)(LVALUE(t_file *, lst2)->name)) < 0);
}

int				main(int ac, char **av)
{
	u_char		flags;


	t_list		*lstf;
	/*t_file		tmp;*/

	DIR				*dirp;
	struct dirent	*dp;
	size_t			len;
	char			*error_msg;
	char			*dir_name;




	/*lstf = ft_lstnew(new_file("", "."), sizeof(t_file));*/
	lstf = (void *)0;

	(void)ac, (void)av;
	flags = 0;
	if (get_options(&ac, &av, &flags) == '?')
		return (-1);
	/*if (F_RECURSIVE(flags))
		ft_putendl("flag R set!!!!");
	if (F_ALL(flags))
		ft_putendl("flag a set!!!!");
	if (F_LONG(flags))
		ft_putendl("flag l set!!!!");
	if (F_REVERSE(flags))
		ft_putendl("flag r set!!!!");
	if (F_TIME(flags))
		ft_putendl("flag t set!!!!");*/
	dir_name = (av[1] ? av[1] : "");
	dirp = opendir(".");
	if (dirp == NULL)
	{
		error_msg = (char *)ft_memalloc(sizeof(char) << 9);
		error_msg = ft_strcat(error_msg, BIN_NAME);
		error_msg = ft_strcat(error_msg, ": ");
		error_msg = ft_strcat(error_msg, dir_name);
		perror(error_msg);
		free(error_msg);
		return (-1);
	}
	len = ft_strlen(av[1]);
	while ((dp = readdir(dirp)) != NULL)
	{
		sort_lstadd(&lstf, ft_lstnew(new_file("", dp->d_name), sizeof(t_file)), cmp);
		/*if (dp->d_namlen == len && !ft_strcmp(dp->d_name, av[1]))
		{
			(void)closedir(dirp);
			ft_putendl(av[1]);
			return (0);
		}*/
	}
	print_list(lstf);
	ft_lstdel(&lstf, del_lstf);
	(void)closedir(dirp);
	return (0);
}
