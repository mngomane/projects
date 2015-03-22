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

# define NOP		0
# define SA			1
# define SB			2
# define SS			3
# define PA			4
# define PB			5
# define RA			6
# define RB			7
# define RR			8
# define RRA		9
# define RRB		10
# define RRR		11

# define BF_LIMIT	9

typedef struct		s_stack
{
	int				*value;
	size_t			size;
}					t_stack;

void				bub_swap(t_stack *l_a, t_stack *l_b);
void				brute_swap(t_stack *l_a, t_stack *l_b, int size);
void				display_stacks(t_stack l_a, t_stack l_b);
int8_t				error_found(int ac, char **av);
void				fset(t_stack *dst, t_stack *src, int8_t *op, size_t index);
int8_t				get_option(char **av);
void				mset(t_stack *dst, t_stack *src, int8_t *op, size_t index);
void				push_elem(t_stack *dest, t_stack *origin);
void				reverse_rotate_all(t_stack *list1, t_stack *list2);
void				reverse_rotate_elem(t_stack *list);
void				rotate_all(t_stack *list1, t_stack *list2);
void				rotate_elem(t_stack *list);
void				scheck(t_stack *dst, t_stack *src, int8_t *op, size_t i);
void				swap_all(t_stack *list1, t_stack *list2);
void				swap_elem(t_stack *list);
int					variations(t_stack *list);

#endif
