/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 19:36:12 by mngomane          #+#    #+#             */
/*   Updated: 2014/05/04 16:50:19 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <termios.h>

/*
** LEFT: 27 91 68
** UP: 27 91 65
** DOWN: 27 91 66
** RIGHT: 27 91 67
** DEL: 27 91 51 126
*/
# define ESC		27
# define SPACE		32
# define UP			65
# define DOWN		66
# define RETURN		10
# define DEL		126
# define BKSP		127
# define X			0
# define Y			1

typedef struct		s_arg
{
	char			*aname;
	size_t			pos;
	size_t			sel;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_var
{
	t_arg			*save;
	size_t			i;
	size_t			narg;
	size_t			buff_len;
	int				first;
	int				quit;
}					t_var;

typedef struct		s_read
{
	ssize_t			ret;
	int				apad;
	char			bpad;
	char			cpad;
	char			buff[42];
}					t_read;

typedef struct		s_term
{
	struct termios	old_config;
	struct termios	new_config;
	char			buff[2048];
	char			*area;
	char			*type;
	size_t			p[2];
	size_t			len;
	int				ret;
	int				pad;
}					t_term;

int					ft_putchar(int c);
int					q_sel(t_term *term, t_arg **arg, t_var *var, t_read *inp);
int					sub_init(t_arg **arg, t_var *var, int ac, char **av);
int					sub_main(t_term *term, t_arg **arg, t_var *var);
int					sub_return(t_term *term, t_arg **arg, t_var *var);
int					term_init(t_term *term, char **ep);
size_t				ft_strlen(char *str);
t_arg				*add_arg(t_arg **arg, char *aname, size_t pos);
void				del_arg(t_term *term, t_arg **arg, t_var *var, size_t pos);
void				del_sel(t_term *term, t_arg **arg, t_var *var, t_read *inp);
void				display_sel(t_term *term, t_arg **arg);
void				ed_sel(t_term *term, t_arg **arg, t_var *var, t_read *inp);
void				*ft_memset(void *s, int c, size_t len);
void				free_arg(t_arg **arg);

#endif
