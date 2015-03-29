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
		file->path = ft_strdup(path);
		if ((file->stat = (t_stat *)ft_memalloc(sizeof(t_stat))))
			if (stat(ft_strjoin(path, name), file->stat) == -1)
				perror("ft_ls: stat");
		file->name = ft_strdup(name);
	}
	return (file);
}

static void		del_lstf(void *file, size_t size)
{
	size = 0;
	free(((t_file *)file)->dirp);
	free(((t_file *)file)->stat);
	free(((t_file *)file)->path);
	free(((t_file *)file)->name);
	free(((t_file *)file)->type);
	free(file);
}

static void		print_list(t_list *lst)
{
	while (lst)
	{
		ft_putendl((char *)(LVALUE(t_file *, lst)->path));
		ft_putendl((char *)(LVALUE(t_file *, lst)->name));
		lst = lst->next;
	}
}

static int		cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp((char *)(LVALUE(t_file *, lst1)->name),
			(char *)(LVALUE(t_file *, lst2)->name)) < 0);
}

static t_list	*init_lst_dot(char *dir_name, int (*cmp)(t_list *, t_list *))
{
	DIR				*dirp;
	struct dirent	*dp;
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
		/*(void)closedir(dirp);
		return (dirp);*/
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

/*static void		fct2(int ac, char **av, u_char flags)
{

}*/

static int		fct1(int ac, char **av, u_char flags)
{
	t_list		*lst;
	t_list		*lstf;
	t_list		*lstd;
	int			i;

	i = 0;
	(void)av, (void)flags, (void)lstf, (void)lstd;
	if (ac < 1)
	{
		if ((lst = init_lst_dot(".", cmp)) == (void *)0)
			return (-1);
		print_list(lst);
		ft_lstdel(&lst, del_lstf);
	}
	/*else
	{
		if ((lstf = init_lstf(".")) == (void *)0)
			return (-1);
	}*/
	return (0);
}

int				main(int ac, char **av)
{
	u_char		flags;

	flags = 0;
	if (get_options(&ac, &av, &flags) == '?')
		return (-1);
	fct1(ac, av, flags);
	return (0);
}
