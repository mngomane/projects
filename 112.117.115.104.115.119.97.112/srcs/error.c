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

char			*int_to_str(const int number)
{
	char	*str;
	int		index;
	int		nbr;
	int		decim;

	index = 0;
	decim = ((number == -2147483648) ? 0 : 1);
	str = (!decim ? str_min_int() : (char *)malloc(sizeof(char) * 12));
	nbr = (int)number;
	if (nbr < 0 && decim)
	{
		str[index] = '-';
		nbr *= -1;
		++index;
	}
	while (decim && (nbr / decim) > 9)
		decim *= 10;
	while (decim > 0 && index < 11)
	{
		str[index] = ((nbr / decim) % 10) + '0';
		++index;
		decim /= 10;
	}
	str[index] = ((index != 0) ? 0 : str[index]);
	return (str);
}

static t_error	not_an_int(const char *argument)
{
	int		nbr;
	char	*str;
	char	*copy;
	t_error	error;

	error = OK;
	copy = (char *)argument;
	nbr = ft_atoi(copy);
	str = int_to_str(nbr);
	if (ft_strncmp(str, copy, 12))
		error = NOT_INT;
	if (str != NULL)
		free(str);
	return (error);
}

static t_error	not_a_number(const char *str)
{
	char	*iterator;

	iterator = (char *)str;
	if (NULL == iterator)
		return (NAN);
	while (*iterator != '\0')
	{
		if (*iterator != *str && !ft_isdigit(*iterator))
			return (NAN);
		++iterator;
	}
	return (OK);
}

t_error			error_found(int ac, char **av)
{
	int		index;
	t_error	ret;

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

t_error			push_quit(t_error error)
{
	if (error != OK)
	{
		write(2, "Error\n", 6);
		return (error);
	}
	return (OK);
}