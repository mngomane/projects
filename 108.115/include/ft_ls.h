/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 17:14:13 by mngomane          #+#    #+#             */
/*   Updated: 2014/04/20 19:50:08 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
# include "libft.h"

# define NAME			"ft_ls"
# define ILLEGAL		NAME": illegal option -"
# define FAILED_ALLOC	"malloc failed"
# define FAILED_STAT	"Stat Error"
# define UNKNOWN_ERROR	"Error"

typedef struct		s_var
{
	char			*fname;
	char			*new_time;
	char			*tmp_time;
	DIR				*dirp;
	size_t			len;
	struct dirent	*dp;
	struct stat		filestat;
	int				ac;
	int				i;
	off_t			size;
	off_t			padding;
}					t_var;

typedef struct		s_opt
{
	char			*oname;
	int				onbr;
	int				padding;
	struct s_opt	*next;
}					t_opt;


int					init_main(t_list **arg, t_opt **op, int ac);
int					valid_op(t_opt **op);
t_list				*add_link(t_list *arg, char *name);
t_opt				*add_opt(t_opt *op, char *name);
void				body_main(t_list *arg, t_opt *op, int ac, char **av);
void				sub_main(t_list *arg, t_opt *op, int ac);
void				fill_arg_list(t_list **arg, int ac, int j, char **av);
void				fill_list(t_list **arg, t_opt **op, int ac, char **av);
void				ft_arg(t_list *arg);
void				ft_noarg(t_list *arg);
void				ft_aarg(t_list *arg);
void				ft_larg(t_list *arg);
void				no_file(t_list *arg, void (*fct[3])(t_list *), int ac);
void				no_lfile(t_list *arg, void (*fct[3])(t_list *), int ac);
void				no_afile(t_list *arg, void (*fct[3])(t_list *), int ac);
void				no_ofile(t_list *arg, void (*fct[3])(t_list *), int ac);
void				sub_nofile(t_list *arg);
void				sub_nolfile(t_list *arg);
void				sub_noafile(t_list *arg);
void				sub_noofile(t_list *arg);
void				sub_nofile2(t_list *arg);
void				sub_nolfile2(t_list *arg);
void				sub_noafile2(t_list *arg);
void				sub_noofile2(t_list *arg);
void				whatelse(char *name);
void				free_link(t_list **arg);
void				apptol(t_list *arg, void (*fct[3])(t_list *));
void				appdir(t_list *arg, void (*fct[3])(t_list *));
void				free_opt(t_opt **op);

#endif
