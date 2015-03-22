/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 23:59:48 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/09 23:59:48 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		display_the_stack(t_stack list)
{
	size_t		i;

	i = 0;
	while (i + 1 < list.size)
		ft_printf("%d ", (list.value)[i++]);
	if (i < list.size)
		ft_putnbr((list.value)[i]);
	write(1, "\n", 1);
}

void			display_stacks(t_stack l_a, t_stack l_b)
{
	ft_printf("%s\n%s", I_NB, I_FSS);
	display_the_stack(l_a);
	ft_putstr(I_SSS);
	display_the_stack(l_b);
}

void			mset(t_stack *dst, t_stack *src, int8_t *op, size_t i)
{
	if (op[i] == SA && ft_putstr(" sa"))
		swap_elem(dst);
	if (op[i] == SB && ft_putstr(" sb"))
		swap_elem(src);
	if (op[i] == SS && ft_putstr(" ss"))
		swap_all(dst, src);
	if (op[i] == PA && ft_putstr(" pa"))
		push_elem(dst, src);
	if (op[i] == PB && ft_putstr(" pb"))
		push_elem(src, dst);
	if (op[i] == RA && dst->size > 1 && ft_putstr(" ra"))
		rotate_elem(dst);
	if (op[i] == RB && src->size > 1 && ft_putstr(" rb"))
		rotate_elem(src);
	if (op[i] == RR && dst->size > 1 && src->size > 1 && ft_putstr(" rr"))
		rotate_all(dst, src);
	if (op[i] == RRA && dst->size > 1 && ft_putstr(" rra"))
		reverse_rotate_elem(dst);
	if (op[i] == RRB && src->size > 1 && ft_putstr(" rrb"))
		reverse_rotate_elem(src);
	if (op[i] == RRR && dst->size > 1 && src->size > 1 && ft_putstr(" rrr"))
		reverse_rotate_all(dst, src);
}

void			fset(t_stack *dst, t_stack *src, int8_t *op, size_t index)
{
	if (op[index] == SA && ft_putstr("sa"))
		swap_elem(dst);
	if (op[index] == SB && ft_putstr("sb"))
		swap_elem(src);
	if (op[index] == SS && ft_putstr("ss"))
		swap_all(dst, src);
	if (op[index] == PA && ft_putstr("pa"))
		push_elem(dst, src);
	if (op[index] == PB && ft_putstr("pb"))
		push_elem(src, dst);
	if (op[index] == RA && dst->size > 1 && ft_putstr("ra"))
		rotate_elem(dst);
	if (op[index] == RB && src->size > 1 && ft_putstr("rb"))
		rotate_elem(src);
	if (op[index] == RR && dst->size > 1 && src->size > 1 && ft_putstr("rr"))
		rotate_all(dst, src);
	if (op[index] == RRA && dst->size > 1 && ft_putstr("rra"))
		reverse_rotate_elem(dst);
	if (op[index] == RRB && src->size > 1 && ft_putstr("rrb"))
		reverse_rotate_elem(src);
	if (op[index] == RRR && dst->size > 1 && src->size > 1 && ft_putstr("rrr"))
		reverse_rotate_all(dst, src);
}

void			scheck(t_stack *dst, t_stack *src, int8_t *op, size_t i)
{
	if (op[i] == SA)
		swap_elem(dst);
	if (op[i] == SB)
		swap_elem(src);
	if (op[i] == SS)
		swap_all(dst, src);
	if (op[i] == PA)
		push_elem(dst, src);
	if (op[i] == PB)
		push_elem(src, dst);
	if (op[i] == RA && dst->size > 1)
		rotate_elem(dst);
	if (op[i] == RB && src->size > 1)
		rotate_elem(src);
	if (op[i] == RR && dst->size > 1 && src->size > 1)
		rotate_all(dst, src);
	if (op[i] == RRA && dst->size > 1)
		reverse_rotate_elem(dst);
	if (op[i] == RRB && src->size > 1)
		reverse_rotate_elem(src);
	if (op[i] == RRR && dst->size > 1 && src->size > 1)
		reverse_rotate_all(dst, src);
}
