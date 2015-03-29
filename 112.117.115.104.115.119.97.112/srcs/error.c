/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 02:00:49 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/10 02:00:49 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int8_t	not_an_int(const char *argument)
{
	int		nbr;
	char	*str;
	char	*copy;
	int8_t	error;

	error = OK;
	copy = (char *)argument;
	nbr = ft_atoi(copy);
	str = ft_itoa(nbr);
	if (ft_strncmp(str, copy, 12))
		error = NOT_INT;
	if (str != (void *)0)
		free(str);
	return (error);
}

static int8_t	not_a_number(const char *str)
{
	char		*iterator;

	iterator = (char *)str;
	if ((void *)0 == iterator)
		return (NAN);
	while (*iterator != '\0')
	{
		if (*iterator != *str && !ft_isdigit(*iterator))
			return (NAN);
		++iterator;
	}
	return (OK);
}

static int8_t	duplicate(int8_t *check, const char *argument)
{
	u_char		mask;
	u_char		bit;
	long		convert;

	convert = (long)ft_atoi(argument) - MIN_INT;
	bit = convert & 7;
	mask = (u_char)(1 << bit);
	if (check[convert / 8] & mask)
		return (DUPLICATE);
	else
		check[convert / 8] ^= mask;
	return (OK);
}

static t_lut	*init_lookup_table(void)
{
	t_lut		*lookup;
	int8_t		ret;

	ret = OK;
	lookup = (t_lut *)ft_memalloc(sizeof(t_lut) << 1);
	lookup[0].key = &ret;
	lookup[0].fct = not_a_number;
	return (lookup);
}

int8_t			error_found(int ac, char **av)
{
	t_lut		*lookup;
	int8_t		*dup_check;
	int8_t		ret;
	int			index;
	int			i;

	index = 1;
	ret = OK;
	dup_check = (int8_t *)ft_memalloc(sizeof(int8_t) * (MAX_UINT / 8 + 2));
	lookup = init_lookup_table();
	while (index < ac && ret == OK)
	{
		i = 0;
		while (lookup[i].fct != (void *)0)
			(*((int8_t *)lookup[i].key) == OK ?
				lookup[i++].fct(av[index]) : i++);
		if (ret == OK)
			ret = not_an_int(av[index]);
		if (ret == OK && dup_check)
			ret = duplicate(dup_check, av[index]);
		++index;
	}
	free(dup_check);
	free(lookup);
	return (ret);
}
