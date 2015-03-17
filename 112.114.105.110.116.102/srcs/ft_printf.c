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

static ssize_t	fct2(const char **format, char conv, va_list *ap)
{
	if ((conv == 'D') && (*format)++)
		return (ft_putnbr_off_t((off_t)va_arg(*ap, long int)));
	else if ((conv == 'U') && (*format)++)
		return (ft_putnbr_off_t((off_t)va_arg(*ap, long int)));
	else if ((conv == 'C') && (*format)++)
		return (ft_putwchar(va_arg(*ap, wchar_t)));
	else if ((conv == 'S') && (*format)++)
		return (ft_putwstr(va_arg(*ap, wchar_t *)));
	return (0);
}

static ssize_t	fct1(const char **format, char conv, va_list *ap)
{
	(*format)++;
	while (**format == '#' || **format == '0' || **format == '-' ||
			**format == '+' || **format == ' ')
		conv = *(++(*format));
	if ((conv == '%') && (*format)++)
		return (write(1, "%", 1));
	else if ((conv == 's') && (*format)++)
		return (ft_putstr(va_arg(*ap, char *)));
	else if ((conv == 'c') && (*format)++)
		return (ft_putchar(va_arg(*ap, int)) ? 1 : 1);
	else if ((conv == 'd' || conv == 'i') && (*format)++)
		return (ft_putnbr(va_arg(*ap, int)));
	else if ((conv == 'p') && (*format)++)
		return (ft_puthexf(va_arg(*ap, uintptr_t)));
	else if ((conv == 'x') && (*format)++)
		return (ft_puthex(va_arg(*ap, uintptr_t)));
	else if ((conv == 'X') && (*format)++)
		return (ft_puthexu(va_arg(*ap, uintptr_t)));
	else if ((conv == 'o' || conv == 'O') && (*format)++)
		return (ft_putoct(va_arg(*ap, uintptr_t)));
	else if ((conv == 'u') && (*format)++)
		return (ft_putnbr_off_t((off_t)va_arg(*ap, uintptr_t)));
	return (fct2(format, conv, ap));
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
