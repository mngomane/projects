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
	if ((*opt)[PF_PADC] == 0)
		(*opt)[PF_PADC] = ' ';
	if ((**format == '#') && ((*opt)[PF_SHARP] = 1))
		return (1);
	else if ((**format == '0') && ((*opt)[PF_ZERO] = 1))
	{
		(*opt)[PF_PADC] = ((*opt)[PF_MINUS] == 0 ? '0' : ' ');
		return (1);
	}
	else if ((**format == '-') && ((*opt)[PF_MINUS] = 1))
	{
		(*opt)[PF_PADC] = ' ';
		return (1);
	}
	else if ((**format == '+') && ((*opt)[PF_PLUS] = 1))
	{
		(*opt)[PF_SIGN] = '+';
		return (1);
	}
	else if ((**format == ' ') && ((*opt)[PF_SPACE] = 1))
	{
		(*opt)[PF_SIGN] = ((*opt)[PF_PLUS] == 0 ? ' ' : '+');
		return (1);
	}
	else if ((**format == '.') && ((*opt)[PF_DOT] = 1))
		return (1);
	else if (ft_isdigit(**format) && **format != '0')
	{
		while (ft_isdigit(**format))
		{
			if ((*opt)[PF_DOT] == 1)
				(*opt)[PF_TMPP + index++] = *((*format)++);
			else
				(*opt)[PF_TMP + index++] = *((*format)++);
		}
		if ((*opt)[PF_DOT] == 1)
			ft_ztom(*opt + PF_PERIOD, (size_t)ft_atoi(*opt + PF_TMPP));
		else
			ft_ztom(*opt + PF_PREC, (size_t)ft_atoi(*opt + PF_TMP));
		return (fct5(format, opt));
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

static ssize_t	fct2(const char **format, va_list *ap, char *opt, size_t len)
{
	if ((**format == 'u') && (*format)++)
	{
		if (opt[PF_L] == 1 || opt[PF_LL] == 1 || opt[PF_J] == 1 || opt[PF_Z] == 1)
			return (ft_printnulong(va_arg(*ap, u_long), opt, len));
		if (opt[PF_H] == 1)
			return (ft_printnushort((u_short)va_arg(*ap, int), opt, len));
		if (opt[PF_HH] == 1)
			return (ft_printnuchar((u_char)va_arg(*ap, int), opt, len));
		return (ft_printnulong((u_long)va_arg(*ap, uintptr_t), opt, len));
	}
	else if ((**format == 'd' || **format == 'i') && (*format)++)
	{
		if (opt[PF_L] == 1 || opt[PF_LL] == 1 || opt[PF_J] == 1 || opt[PF_Z] == 1)
			return (ft_printnlong(va_arg(*ap, long), opt, len));
		if (opt[PF_H] == 1)
			return (ft_printnshort((short)va_arg(*ap, int), opt, len));
		if (opt[PF_HH] == 1)
			return (ft_printnchar((char)va_arg(*ap, int), opt, len));
		return (ft_printnint(va_arg(*ap, int), opt, len));
	}
	else if ((**format == 'D') && (*format)++)
		return (ft_printnlong(va_arg(*ap, long int), opt, len));
	else if ((**format == 'U') && (*format)++)
		return (ft_printnulong(va_arg(*ap, u_long), opt, len));
	else if ((**format == 'C') && (*format)++)
		return (ft_printnwchar(va_arg(*ap, wchar_t), opt, len));
	else if ((**format == 'S') && (*format)++)
		return (ft_printnwstr(va_arg(*ap, wchar_t *), opt, len));
	else if (**format == 0)
		return (0);
	return ((len ? ft_putnchar(opt[PF_PADC], len - 1) : 0) + write(1, (*format)++, 1));
}

static ssize_t	fct1(const char **format, va_list *ap, char *opt, size_t len)
{
	if ((**format == '%') && (*format)++)
		return (write(1, "%", 1));
	else if ((**format == 's') && (*format)++)
	{
		if (opt[PF_L] == 1 || opt[PF_LL] == 1)
			return (ft_printnwstr(va_arg(*ap, wchar_t *), opt, len));
		return (ft_printnstr(va_arg(*ap, char *), opt, len));
	}
	else if ((**format == 'c') && (*format)++)
	{
		if (opt[PF_L] == 1 || opt[PF_LL] == 1)
			return (ft_printnwchar(va_arg(*ap, wchar_t), opt, len));
		return (ft_printnc(va_arg(*ap, int), opt, len));
	}
	else if ((**format == 'p') && (*format)++)
		return (ft_printnhexpf(va_arg(*ap, uintptr_t), opt, len));
	else if ((**format == 'x') && (*format)++)
	{
		if (opt[PF_H] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnhexf((u_short)va_arg(*ap, int), opt, len));
		if (opt[PF_H] == 1)
			return (ft_printnhex((u_short)va_arg(*ap, int), opt, len));
		if (opt[PF_HH] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnhexf((u_char)va_arg(*ap, int), opt, len));
		if (opt[PF_HH] == 1)
			return (ft_printnhex((u_char)va_arg(*ap, int), opt, len));
		if (opt[PF_SHARP] == 1)
			return (ft_printnhexf(va_arg(*ap, uintptr_t), opt, len));
		return (ft_printnhex(va_arg(*ap, uintptr_t), opt, len));
	}
	else if ((**format == 'X') && (*format)++)
	{
		if (opt[PF_H] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnhexuf((u_short)va_arg(*ap, int), opt, len));
		if (opt[PF_H] == 1)
			return (ft_printnhexu((u_short)va_arg(*ap, int), opt, len));
		if (opt[PF_HH] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnhexuf((u_char)va_arg(*ap, int), opt, len));
		if (opt[PF_HH] == 1)
			return (ft_printnhexu((u_char)va_arg(*ap, int), opt, len));
		if (opt[PF_SHARP] == 1)
			return (ft_printnhexuf(va_arg(*ap, uintptr_t), opt, len));
		return (ft_printnhexu(va_arg(*ap, uintptr_t), opt, len));
	}
	else if ((**format == 'o') && (*format)++)
	{
		if (opt[PF_H] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnoctf((u_short)va_arg(*ap, int), opt, len));
		if (opt[PF_H] == 1)
			return (ft_printnoct((u_short)va_arg(*ap, int), opt, len));
		if (opt[PF_HH] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnoctf((u_char)va_arg(*ap, int), opt, len));
		if (opt[PF_HH] == 1)
			return (ft_printnoct((u_char)va_arg(*ap, int), opt, len));
		if (opt[PF_SHARP] == 1)
			return (ft_printnoctf(va_arg(*ap, uintptr_t), opt, len));
		return (ft_putoct(va_arg(*ap, uintptr_t)));
	}
	else if ((**format == 'O') && (*format)++)
	{
		if (opt[PF_H] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnoctf(va_arg(*ap, uintptr_t), opt, len));
		if (opt[PF_H] == 1)
			return (ft_printnoct(va_arg(*ap, uintptr_t), opt, len));
		if (opt[PF_HH] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnoctf(va_arg(*ap, uintptr_t), opt, len));
		if (opt[PF_HH] == 1)
			return (ft_printnoct(va_arg(*ap, uintptr_t), opt, len));
		if (opt[PF_SHARP] == 1)
			return (ft_printnoctf(va_arg(*ap, uintptr_t), opt, len));
		return (ft_printnoct(va_arg(*ap, uintptr_t), opt, len));
	}
	return (fct2(format, ap, opt, len));
}

static void		fct6(const char **format, char **opt)
{
	(*format)++;
	while (fct5(format, opt))
		++(*format);
	while (fct3(format, opt))
		++(*format);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*opt;
	ssize_t		ret;
	ssize_t		tmp;

	ret = 0;
	tmp = 0;
	opt = ft_memalloc(256 * sizeof(char));
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			fct6(&format, &opt);
			if (opt[PF_DOT] == 1)
				opt[PF_PADC] = '0';
			if (opt[PF_MINUS] == 1)
				tmp = fct1(&format, &ap, opt, 0);
			else
			{
				if (ft_mtoz(opt + PF_PREC) < ft_mtoz(opt + PF_PERIOD))
					tmp = fct1(&format, &ap, opt, ft_mtoz(opt + PF_PERIOD));
				else if (ft_mtoz(opt + PF_PERIOD))
				{
					/*tmp = ft_putnchar(' ', ft_mtoz(opt + PF_PREC) -
						ft_mtoz(opt + PF_PERIOD));*/
					tmp = fct1(&format, &ap, opt, ft_mtoz(opt + PF_PERIOD));
				}
				else
					tmp = fct1(&format, &ap, opt, ft_mtoz(opt + PF_PREC));
			}
			if ((opt[PF_MINUS] == 1) &&
				(((ssize_t)ft_mtoz(opt + PF_PREC) - tmp) > 0))
				ret += ft_putnchar(opt[PF_PADC],
					ft_mtoz(opt + PF_PREC) - (size_t)tmp);
			ret += tmp;
		}
		else
			ret += (*format ? write(1, format++, 1) : 0);
	}
	va_end(ap);
	free(opt);
	return ((int)ret);
}
