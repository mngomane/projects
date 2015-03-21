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
# include "libft.h"

typedef struct		s_stack
{
	int				*value;
	size_t			size;
}					t_stack;

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

void				display_stacks(t_stack l_a, t_stack l_b);
t_error				error_found(int ac, char **av);
void				ft_abs(int *n);
void				ft_p(t_stack *tab1, t_stack *tab2);
void				ft_r(t_stack *list);
void				ft_rr(t_stack *list);
void				ft_s(t_stack *list);
void				ft_ss(t_stack *list1, t_stack *list2);
void				bub_swap(t_stack *l_a, t_stack *l_b);
int					variations(t_stack *list);
t_option			get_swap_option(char **av);
t_error				push_quit(t_error error);
char				*str_min_int(void);

#endif
