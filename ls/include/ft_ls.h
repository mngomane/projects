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
# include <sys/stat.h>
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

# define LGROUP(x)		((t_group *)LVALUE(t_file *, x)->group)
# define LLINK(x)		((char *)LVALUE(t_file *, x)->link)
# define LNAME(x)		((char *)LVALUE(t_file *, x)->name)
# define LPASS(x)		((t_passwd *)LVALUE(t_file *, x)->passwd)
# define LSTAT(x)		((t_stat *)LVALUE(t_file *, x)->stat)

# define SIZE_MONTHS	2592000

# define E_ELOOP_MSG	"Too many levels of symbolic links"
# define E_ENOENT_MSG	"No such file or directory"

typedef struct group	t_group;
typedef struct passwd	t_passwd;
typedef struct stat		t_stat;

typedef struct			s_lut
{
	void				*key;
	void				(*fct)(void *, void *);
}						t_lut;

typedef struct			s_file
{
	t_group				*group;
	t_passwd			*passwd;
	t_stat				*stat;
	void				*name;
	void				*link;
}						t_file;

void					del_lst(void *file, size_t size);
ssize_t					display_rights(t_stat *cstat);
char					*entry_type(mode_t mode);
int						fdisplay(int ac, char **av, char *name, u_char flags);
int						get_options(int *ac, char ***av, void *flags);
char					*group_perm(mode_t mode);
t_list					*ilst(char *name, int (*cmp)(t_list *, t_list *),
							u_char flags, quad_t *block);
char					*init_time(t_stat *cstat);
int						lexical_cmp(t_list *lst1, t_list *lst2);
t_file					*new_file(void *path, void *name, u_char flags,
							quad_t *block);
char					*other_perm(mode_t mode);
char					*owner_perm(mode_t mode);
void					print_lst(t_list *lst, u_char flags, quad_t block);
int						putendlong(t_list *lst);
int						reverse_cmp(t_list *lst1, t_list *lst2);
int						rtime_cmp(t_list *lst1, t_list *lst2);
int						time_cmp(t_list *lst1, t_list *lst2);

#endif
