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

# include "libft.h"

# define I_NB		"NB: The first number displayed is on the top of the stack !!!"
# define I_FSS		"First stack state : "
# define I_SSS		"Second stack state: "
# define I_ERROR	"Error\n"

# define OK			0
# define NAN		1
# define NOT_INT	2
# define DUPLICATE	3
# define NONE		0
# define DEBUG		1
# define MIN_INT	(-2147483648)
# define MAX_UINT	4294967295

typedef struct		s_stack
{
	int				*value;
	size_t			size;
}					t_stack;

void				display_stacks(t_stack l_a, t_stack l_b);
int8_t				error_found(int ac, char **av);
void				ft_p(t_stack *tab1, t_stack *tab2);
void				ft_r(t_stack *list);
void				ft_rr(t_stack *list);
void				ft_s(t_stack *list);
void				ft_ss(t_stack *list1, t_stack *list2);
void				bub_swap(t_stack *l_a, t_stack *l_b);
int8_t				get_option(char **av);

#endif
