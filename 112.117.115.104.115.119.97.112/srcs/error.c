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

	bit = (ft_atoi(argument) - MIN_INT) % 8;
	if (bit == 0)
		mask = 0x01;
	else if (bit == 1)
		mask = 0x02;
	else if (bit == 2)
		mask = 0x04;
	else if (bit == 3)
		mask = 0x08;
	else if (bit == 4)
		mask = 0x10;
	else if (bit == 5)
		mask = 0x20;
	else if (bit == 6)
		mask = 0x40;
	else
		mask = 0x80;
	if (check[(ft_atoi(argument) - MIN_INT) / 8] & mask)
		return (DUPLICATE);
	else
		check[(ft_atoi(argument) - MIN_INT) / 8] ^= mask;
	return (OK);
}

int8_t			error_found(int ac, char **av)
{
	int8_t		*dup_check;
	int8_t		ret;
	int			index;

	index = 1;
	ret = OK;
	dup_check = (int8_t *)ft_memalloc(sizeof(int8_t) * (MAX_UINT / 8 + 2));
	while (index < ac && ret == OK)
	{
		if (ret == OK)
			ret = not_a_number(av[index]);
		if (ret == OK)
			ret = not_an_int(av[index]);
		if (ret == OK && dup_check)
			ret = duplicate(dup_check, av[index]);
		++index;
	}
	free(dup_check);
	return (ret);
}
