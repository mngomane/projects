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

static int		fct5(const char **format, char **opt)
{
	size_t		index;

	index = 0;
	if ((**format == '#') && ((*opt)[PF_SHARP] = 1))
		return (1);
	else if ((**format == '0') && ((*opt)[PF_ZERO] = 1))
		return (1);
	else if ((**format == '-') && ((*opt)[PF_MINUS] = 1))
		return (1);
	else if ((**format == '+') && ((*opt)[PF_PLUS] = 1))
		return (1);
	else if ((**format == ' ') && ((*opt)[PF_SPACE] = 1))
		return (1);
	else if (ft_isdigit(**format))
	{
		while (ft_isdigit(**format))
			(*opt)[PF_TMP + index++] = *((*format)++);
		ft_ztom(*opt + PF_PREC, (size_t)ft_atoi(*opt + PF_TMP));
		return (1);
	}
	return (0);
}

static int		fct4(const char **format, char **opt)
{
	if (**format == 'l')
	{
		if ((*(*format + 1) == 'l') && ((*opt)[PF_LL] = 1) && (*format)++)
			return (2);
		((*opt)[PF_L] = 1);
		return (1);
	}
	else if (**format == 'h')
	{
		if ((*(*format + 1) == 'h') && ((*opt)[PF_HH] = 1) && (*format)++)
			return (2);
		((*opt)[PF_H] = 1);
		return (1);
	}
	return (0);
}

static int		fct3(const char **format, char **opt)
{
	if ((**format == 'j') && ((*opt)[PF_J] = 1))
		return (1);
	else if ((**format == 'z') && ((*opt)[PF_Z] = 1))
		return (1);
	return (fct4(format, opt));
}

static ssize_t	fct2(const char **format, char conv, va_list *ap, char *opt)
{
	if ((conv == 'u') && (*format)++)
	{
		if (opt[PF_L] == 1 || opt[PF_LL] == 1 || opt[PF_J] == 1)
			return (ft_putulong(va_arg(*ap, u_long)));
		if (opt[PF_H] == 1)
			return (ft_putushort((u_short)va_arg(*ap, int)));
		if (opt[PF_HH] == 1)
			return (ft_printuchar((u_char)va_arg(*ap, int)));
		if (opt[PF_Z] == 1)
			return (ft_putulong(va_arg(*ap, size_t)));
		return (ft_putulong((u_long)va_arg(*ap, uintptr_t)));
	}
	else if ((conv == 'd' || conv == 'i') && (*format)++)
	{
		if (opt[PF_L] == 1 || opt[PF_LL] == 1 || opt[PF_J] == 1)
			return (ft_putlong(va_arg(*ap, long)));
		if (opt[PF_H] == 1)
			return (ft_putshort((short)va_arg(*ap, int)));
		if (opt[PF_HH] == 1)
			return (ft_printchar((char)va_arg(*ap, int)));
		if (opt[PF_Z] == 1)
			return (ft_putlong((long)va_arg(*ap, uintptr_t)));
		return (ft_putnbr(va_arg(*ap, int)));
	}
	else if ((conv == 'D') && (*format)++)
		return (ft_putlong(va_arg(*ap, long int)));
	else if ((conv == 'U') && (*format)++)
		return (ft_putulong(va_arg(*ap, u_long)));
	else if ((conv == 'C') && (*format)++)
		return (ft_putwchar(va_arg(*ap, wchar_t)));
	else if ((conv == 'S') && (*format)++)
		return (ft_putwstr(va_arg(*ap, wchar_t *)));
	return (0);
}

static ssize_t	fct1(const char **format, char conv, va_list *ap, char **opt)
{
	ssize_t		ret;

	ret = 0;
	(void)ret;
	(*format)++;
	while (fct5(format, opt))
		conv = *(++(*format));
	while (fct3(format, opt))
		conv = *(++(*format));
	if ((conv == '%') && (*format)++)
		return (write(1, "%", 1));
	else if ((conv == 's') && (*format)++)
	{
		if ((*opt)[PF_L] == 1 || (*opt)[PF_LL] == 1)
			return (ft_putwstr(va_arg(*ap, wchar_t *)));
		return (ft_putstr(va_arg(*ap, char *)));
	}
	else if ((conv == 'c') && (*format)++)
	{
		if ((*opt)[PF_L] == 1 || (*opt)[PF_LL] == 1)
			return (ft_putwchar(va_arg(*ap, wchar_t)));
		return (ft_putchar(va_arg(*ap, int)) ? 1 : 1);
	}
	else if ((conv == 'p') && (*format)++)
		return (ft_puthexf(va_arg(*ap, uintptr_t)));
	else if ((conv == 'x') && (*format)++)
	{
		if ((*opt)[PF_H] == 1)
			return (ft_puthex((u_short)va_arg(*ap, int)));
		if ((*opt)[PF_HH] == 1)
			return (ft_puthex((u_char)va_arg(*ap, int)));
		return (ft_puthex(va_arg(*ap, uintptr_t)));
	}
	else if ((conv == 'X') && (*format)++)
	{
		if ((*opt)[PF_H] == 1)
			return (ft_puthexu((u_short)va_arg(*ap, int)));
		if ((*opt)[PF_HH] == 1)
			return (ft_puthexu((u_char)va_arg(*ap, int)));
		return (ft_puthexu(va_arg(*ap, uintptr_t)));
	}
	else if ((conv == 'o') && (*format)++)
	{
		if ((*opt)[PF_H] == 1)
			return (ft_putoct((u_short)va_arg(*ap, int)));
		if ((*opt)[PF_HH] == 1)
			return (ft_putoct((u_char)va_arg(*ap, int)));
		return (ft_putoct(va_arg(*ap, uintptr_t)));
	}
	else if ((conv == 'O') && (*format)++)
	{
		if ((*opt)[PF_H] == 1)
			return (ft_putoct((u_short)va_arg(*ap, uintptr_t)));
		if ((*opt)[PF_HH] == 1)
			return (ft_putoct((u_char)va_arg(*ap, uintptr_t)));
		return (ft_putoct(va_arg(*ap, uintptr_t)));
	}
	return (fct2(format, conv, ap, *opt));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*opt;
	ssize_t		ret;

	ret = 0;
	opt = ft_memalloc(256 * sizeof(char));
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ret += fct1(&format, *(format + 1), &ap, &opt);
		else
			ret += (*format ? write(1, format++, 1) : 0);
	}
	va_end(ap);
	free(opt);
	return ((int)ret);
}
