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

/*static void		print_list2(t_list *lst)
{
	while (lst)
	{
		if (LVALUE(t_file *, lst)->stat != (void *)0 &&
			!(LVALUE(t_file *, lst)->stat->st_mode & S_IFDIR))
		{
			ft_putendl((char *)(LVALUE(t_file *, lst)->name));
		}
		lst = lst->next;
	}
}*/

static void		print_list(t_list *lst)
{
	while (lst)
	{
		if (LVALUE(t_file *, lst)->stat != (void *)0)
		{
			/*ft_putendl((char *)(LVALUE(t_file *, lst)->path));*/
			ft_putendl((char *)(LVALUE(t_file *, lst)->name));
		}
		lst = lst->next;
	}
}

static int		cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp((char *)(LVALUE(t_file *, lst1)->name),
			(char *)(LVALUE(t_file *, lst2)->name)) < 0);
}

static t_list	*init_lst(char *dir_name, int (*cmp)(t_list *, t_list *))
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

static int		fct1(int ac, char **av, char *d_name, u_char flags);

static void		fct4(t_list **lstf, u_char flags)
{
	t_list		*save;
	int			first;

	first = 1;
	save = *lstf;
	while (*lstf)
	{
		if (LVALUE(t_file *, *lstf)->stat != (void *)0 &&
			(LVALUE(t_file *, *lstf)->stat->st_mode & S_IFDIR))
		{
			(first ? first = 0 : ft_putendl(""));
			ft_printf("%s:\n", (char *)(LVALUE(t_file *, *lstf)->name));
			/*ft_putendl((char *)(LVALUE(t_file *, *lstf)->name));*/
			/*__asm("int3");*/
			fct1(0, NULL, (char *)(LVALUE(t_file *, *lstf)->name), flags);
		}
		*lstf = (*lstf)->next;
	}
	*lstf = save;
	ft_lstdel(lstf, del_lstf);
}

static t_list	*fct3(t_list *lstf, u_char flags)
{
	/*t_list		*lstd;*/
	t_list		*save;

	(void)flags;
	/*lstd = (void *)0;*/
	save = lstf;
	while (lstf)
	{
		if (LVALUE(t_file *, lstf)->stat != (void *)0 &&
			!(LVALUE(t_file *, lstf)->stat->st_mode & S_IFDIR))
		{
			ft_putendl((char *)(LVALUE(t_file *, lstf)->name));
		}
		/*else if (LVALUE(t_file *, *lstf)->stat != (void *)0)
			ft_lstadd_tail(&lstd, ft_lstnew((*lstf)->content, sizeof(t_file)));*/
		lstf = lstf->next;
	}
	lstf = save;
	/*ft_lstdel(lstf, del_lstf);*/
	/*print_list2(lstf);*/
	return (lstf);
}

static t_list	*fct2(int ac, char **av, u_char flags)
{
	t_list		*lstf;
	int			i;

	(void)ac, (void)av, (void)flags;
	i = 1;
	lstf = (void *)0;
	sort_lstadd(NULL, NULL, NULL);
	while (i < ac + 1)
		sort_lstadd(&lstf, ft_lstnew(new_file("", av[i++]), sizeof(t_file)), cmp);
	return (lstf);
}

static int		fct1(int ac, char **av, char *d_name, u_char flags)
{
	t_list		*lst;
	t_list		*lstf;
	t_list		*lstd;

	(void)av, (void)flags, (void)lstf, (void)lstd;
	if (ac < 1)
	{
		if ((lst = init_lst(d_name, cmp)) == (void *)0)
			return (-1);
		print_list(lst);
		ft_lstdel(&lst, del_lstf);
	}
	else
	{
		lstf = fct2(ac, av, flags);
		/*print_list(lstf);*/
		lstf = fct3(lstf, flags);
		ft_putendl("");
		fct4(&lstf, flags);
		/*print_list(lstd);
		ft_lstdel(&lstd, del_lstf);
		ft_lstdel(&lstf, del_lstf);*/
	}
	return (0);
}

int				main(int ac, char **av)
{
	u_char		flags;

	flags = 0;
	if (get_options(&ac, &av, &flags) == '?')
		return (-1);
	fct1(ac, av, ".", flags);
	return (0);
}
