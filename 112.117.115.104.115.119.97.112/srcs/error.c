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

int8_t			error_found(int ac, char **av)
{
	int		index;
	int8_t	ret;

	index = 1;
	while (index < ac)
	{
		if ((ret = not_a_number(av[index])) != OK)
			return (ret);
		if ((ret = not_an_int(av[index])) != OK)
			return (ret);
		++index;
	}
	return (OK);
}
