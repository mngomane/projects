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

static char		*fct1(int const c)
{
	if (c == 's')
		return ("char *");
	return ((void *)0);
}

static ssize_t	fct2(const char **format, char *type, va_list *ap)
{
	char	*str;

	(*format)++;
	if (!ft_strncmp(type, "char *", sizeof("char *")) && (*format)++)
	{
		str = va_arg(*ap, char *);
		return (ft_putstr(str));
	}
	return (write(1, "%", 1));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	ssize_t		ret;
	char		*type;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && ((type = fct1(*(format + 1))) != (void *)0))
			ret += fct2(&format, type, &ap);
		else
			ret += (*format ? write(1, format++, 1) : 0);
	}
	va_end(ap);
	return ((int)ret);
}
