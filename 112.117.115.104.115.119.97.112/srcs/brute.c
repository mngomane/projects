/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 04:09:34 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/22 04:09:34 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	check_op(int8_t *op)
{
	size_t		index;

	index = 0;
	while (index < BF_LIMIT)
		if (op[index++] != RRR)
			return (1);
	return (0);
}

]static size_t	set_ret(t_stack *l_a, t_stack *l_b, int8_t *op)
{
	size_t	index;

	index = 0;
	fset(l_a, l_b, op, index++);
	while (op[index] && index < BF_LIMIT)
		mset(l_a, l_b, op, index++);
	write(1, "\n", 1);
	return (0);
}

static size_t	test_op(t_stack *l_a, t_stack *l_b, int8_t *op, int size)
{
	t_stack		copy_a;
	t_stack		copy_b;
	size_t		ret;
	size_t		index;

	ret = 1;
	index = 0;
	ft_bzero(&copy_a, sizeof(t_stack));
	ft_bzero(&copy_b, sizeof(t_stack));
	copy_a.value = (int *)ft_memalloc(sizeof(int) * BF_LIMIT);
	while (index < BF_LIMIT)
	{
		copy_a.value[index] = l_a->value[index];
		++index;
	}
	copy_a.size = l_a->size;
	index = 0;
	while (index < BF_LIMIT)
		scheck(&copy_a, &copy_b, op, index++);
	if (variations(&copy_a) == size && copy_b.size == 0)
		ret = set_ret(l_a, l_b, op);
	free(copy_a.value);
	return (ret);
}

static void		set_op(int8_t (*op)[BF_LIMIT], size_t index, int size)
{
	if (index < (size_t)size)
	{
		if ((*op)[index] == RRR)
		{
			set_op(op, index + 1, size);
			(*op)[index] = SA;
		}
		else
			(*op)[index]++;
	}
}

void			brute_swap(t_stack *l_a, t_stack *l_b, int size)
{
	int8_t		op[BF_LIMIT];
	size_t		do_it;
	size_t		index;

	index = 0;
	do_it = 1;
	ft_memset(op, 0, sizeof(int8_t) * BF_LIMIT);
	while (do_it && index < BF_LIMIT)
	{
		do_it = check_op(op);
		set_op(&op, 0, size);
		do_it = test_op(l_a, l_b, op, size);
	}
}
