/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 23:34:57 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/26 23:34:57 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <time.h>
# include "libft.h"

# define BIN_NAME		"ft_ls"
# define BIN_USAGE		"usage: "BIN_NAME" [-Ralrt] [file ...]\n"

# define F_RECURSIVE(x)	(x & 0x01)
# define F_ALL(x)		(x & 0x02)
# define F_LONG(x)		(x & 0x04)
# define F_REVERSE(x)	(x & 0x08)
# define F_TIME(x)		(x & 0x10)

# define M_FILE			0x01
# define M_ONEDIR		0x02
# define M_MOREDIR		0x04
# define M_FIRST		0x08

typedef struct stat		t_stat;

typedef struct			s_lut
{
	void				*key;
	void				(*fct)(void *, void *);
}						t_lut;

typedef struct			s_file
{
	struct stat			*stat;
	void				*name;
}						t_file;

void					del_lst(void *file, size_t size);
void					display_rights(t_stat *cstat);
int						fdisplay(int ac, char **av, char *name, u_char flags);
int						get_options(int *ac, char ***av, void *flags);
t_list					*ilst(char *dir_name, int (*cmp)(t_list *, t_list *));
char					*init_time(t_stat *cstat);
int						lexical_cmp(t_list *lst1, t_list *lst2);
t_file					*new_file(void *path, void *name);
void					print_lst(t_list *lst, u_char flags);
void					putendlong(t_list *lst);
int						reverse_cmp(t_list *lst1, t_list *lst2);
int						time_cmp(t_list *lst1, t_list *lst2);
int						rtime_cmp(t_list *lst1, t_list *lst2);

#endif
