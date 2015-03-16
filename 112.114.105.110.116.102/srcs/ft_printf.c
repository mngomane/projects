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

static ssize_t	fct1(const char **format, char conv, va_list *ap)
{
	char	c;
	char	*str;
	wchar_t	*wstr;
	ssize_t	nbr;
	int		tab[6];

	(void)wstr;
	ft_bzero(&tab, sizeof(tab));
	(*format)++;
	while (**format == '#' || **format == '0' || **format == '-' ||
			**format == '+' || **format == ' ')
		conv = *(++(*format));
	if ((conv == '%') && (*format)++)
		return (write(1, "%", 1));
	else if ((conv == 's') && (*format)++)
	{
		str = va_arg(*ap, char *);
		return (ft_putstr(str));
	}
	else if ((conv == 'c') && (*format)++)
	{
		c = (char)va_arg(*ap, int);
		return (write(1, &c, 1));
	}
	else if ((conv == 'd') && (*format)++)
	{
		nbr = (ssize_t)va_arg(*ap, int);
		return (ft_putnbr((int)nbr));
	}
	else if ((conv == 'p') && (*format)++)
	{
		nbr = (ssize_t)va_arg(*ap, uintptr_t);
		return (ft_puthex((uintptr_t)nbr));
	}
	return (0);
}


int				ft_printf(const char *format, ...)
{
	va_list		ap;
	ssize_t		ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ret += fct1(&format, *(format + 1), &ap);
		else
			ret += (*format ? write(1, format++, 1) : 0);
	}
	va_end(ap);
	return ((int)ret);
}
