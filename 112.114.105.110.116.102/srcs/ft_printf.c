/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 20:44:09 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/15 20:44:09 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*array[P_MAXARGS + 1];
	int		index;
	int		ret;

	index = 0;
	va_start(ap, format);
	while (format && index < P_MAXARGS)
	{
		array[index++] = (char *)format;
		format = va_arg(ap, const char *);
		ft_putendl("REACHED");
	}
	array[index] = (void *)0;
	ret = (int)ft_putstr(array[0]);
	va_end(ap);
	return (ret);
}
