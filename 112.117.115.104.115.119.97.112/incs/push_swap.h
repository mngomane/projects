/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 23:19:21 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/09 23:19:21 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libfts/incs/libfts.h"

typedef struct		s_index
{
	int				val;
	int				padding;
	size_t			ind;
}					t_index;

typedef struct		s_var
{
	int				*tmp1;
	int				*tmp2;
	int				tmp3;
	int				padding;
	size_t			i;
}					t_var;

typedef struct		s_var2
{
	int				vs;
	int				ve;
	int				vl;
	struct s_var2	*prev;
	struct s_var2	*next;
}					t_var2;

typedef struct		s_list
{
	int				*value;
	size_t			len;
}					t_list;

typedef enum		e_option
{
	NONE,
	DEBUG
}					t_option;

typedef enum		e_error
{
	OK,
	NAN,
	NOT_INT
}					t_error;

void				ft_abs(int *n);
void				ft_filltab(t_list *l_a, size_t *i, char **av);
void				ft_p(t_list *tab1, t_list *tab2);
void				ft_putnbr(int n);
int					ft_strncmp(char *s1, char *s2, size_t len);
void				ft_r(t_list *tab);
void				ft_rr(t_list *tab);
void				ft_s(t_list *tab);
void				ft_ss(t_list *tab1, t_list *tab2);
void				ft_varinit(t_var *v, t_list *tab1, t_list *tab2);
void				ft_varinit2(t_list *l_a, t_list *l_b, size_t *i, int *ac);
int					ft_var(t_list tab);
void				ft_swap1(t_list *l_a, t_list *l_b, size_t *i, t_index *tmp);
void				ft_swap2(t_list *l_a, t_list *l_b);
void				display_stacks(t_list l_a, t_list l_b);
t_option			get_swap_option(char **av);
t_error				error_found(int ac, char **av);
t_error				push_quit(t_error error);
char				*int_to_str(const int number);
char				*str_min_int(void);

#endif
