/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 02:07:47 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/20 02:07:47 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_printf_mod5(const char **format, va_list *ap, char *op)
{
	ssize_t		ret;

	ret = 0;
	if ((**format == 'u') && (*format)++)
	{
		if (op[PF_L] == 1 || op[PF_LL] == 1 || op[PF_J] == 1 || op[PF_Z] == 1)
			return (ft_printnulong(va_arg(*ap, u_long), op));
		if (op[PF_H] == 1)
			return (ft_printnushort((u_short)va_arg(*ap, int), op));
		if (op[PF_HH] == 1)
			return (ft_printnuchar((u_char)va_arg(*ap, int), op));
		return (ft_printnulong((u_long)va_arg(*ap, uintptr_t), op));
	}
	else if ((**format == 'D') && (*format)++)
		return (ft_printnlong(va_arg(*ap, long int), op));
	else if ((**format == 'U') && (*format)++)
		return (ft_printnulong(va_arg(*ap, u_long), op));
	else if (**format == 0)
		return (0);
	if (op[PF_MINUS] == 1 || ft_mtoz(op + PF_PREC) == 0)
		return (write(1, (*format)++, 1));
	ret += ft_putnchar(op[PF_PADC], ft_mtoz(op + PF_PREC) - 1);
	return (ret + write(1, (*format)++, 1));
}

static ssize_t	ft_printf_mod4(const char **format, va_list *ap, char *opt)
{
	if ((**format == 'C') && (*format)++)
		return (ft_printnwchar(va_arg(*ap, wchar_t), opt));
	else if ((**format == 'S') && (*format)++)
		return (ft_printnwstr(va_arg(*ap, wchar_t *), opt));
	else if ((**format == 'O') && (*format)++)
	{
		if (opt[PF_H] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnoctf(va_arg(*ap, uintptr_t), opt));
		if (opt[PF_H] == 1)
			return (ft_printnoct(va_arg(*ap, uintptr_t), opt));
		if (opt[PF_HH] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnoctf(va_arg(*ap, uintptr_t), opt));
		if (opt[PF_HH] == 1)
			return (ft_printnoct(va_arg(*ap, uintptr_t), opt));
		if (opt[PF_SHARP] == 1)
			return (ft_printnoctf(va_arg(*ap, uintptr_t), opt));
		return (ft_printnoct(va_arg(*ap, uintptr_t), opt));
	}
	return (ft_printf_mod5(format, ap, opt));
}

static ssize_t	ft_printf_mod3(const char **format, va_list *ap, char *op)
{
	if ((**format == 'd' || **format == 'i') && (*format)++)
	{
		if (op[PF_L] == 1 || op[PF_LL] == 1 || op[PF_J] == 1 || op[PF_Z] == 1)
			return (ft_printnlong(va_arg(*ap, long), op));
		if (op[PF_H] == 1)
			return (ft_printnshort((short)va_arg(*ap, int), op));
		if (op[PF_HH] == 1)
			return (ft_printnchar((char)va_arg(*ap, int), op));
		return (ft_printnint(va_arg(*ap, int), op));
	}
	else if ((**format == 'X') && (*format)++)
	{
		if (op[PF_H] == 1 && op[PF_SHARP] == 1)
			return (ft_printnhexuf((u_short)va_arg(*ap, int), op));
		if (op[PF_H] == 1)
			return (ft_printnhexu((u_short)va_arg(*ap, int), op));
		if (op[PF_HH] == 1 && op[PF_SHARP] == 1)
			return (ft_printnhexuf((u_char)va_arg(*ap, int), op));
		if (op[PF_HH] == 1)
			return (ft_printnhexu((u_char)va_arg(*ap, int), op));
		if (op[PF_SHARP] == 1)
			return (ft_printnhexuf(va_arg(*ap, uintptr_t), op));
		return (ft_printnhexu(va_arg(*ap, uintptr_t), op));
	}
	return (ft_printf_mod4(format, ap, op));
}

static ssize_t	ft_printf_mod2(const char **format, va_list *ap, char *opt)
{
	if ((**format == 'x') && (*format)++)
	{
		if (opt[PF_H] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnhexf((u_short)va_arg(*ap, int), opt));
		if (opt[PF_H] == 1)
			return (ft_printnhex((u_short)va_arg(*ap, int), opt));
		if (opt[PF_HH] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnhexf((u_char)va_arg(*ap, int), opt));
		if (opt[PF_HH] == 1)
			return (ft_printnhex((u_char)va_arg(*ap, int), opt));
		if (opt[PF_SHARP] == 1)
			return (ft_printnhexf(va_arg(*ap, uintptr_t), opt));
		return (ft_printnhex(va_arg(*ap, uintptr_t), opt));
	}
	else if ((**format == 'p') && (*format)++)
		return (ft_printnhexpf(va_arg(*ap, uintptr_t), opt));
	else if ((**format == 's') && (*format)++)
	{
		if (opt[PF_L] == 1 || opt[PF_LL] == 1)
			return (ft_printnwstr(va_arg(*ap, wchar_t *), opt));
		return (ft_printnstr(va_arg(*ap, char *), opt));
	}
	return (ft_printf_mod3(format, ap, opt));
}

ssize_t			ft_printf_mod(const char **format, va_list *ap, char *opt)
{
	if ((**format == '%') && (*format)++)
		return (write(1, "%", 1));
	else if ((**format == 'c') && (*format)++)
	{
		if (opt[PF_L] == 1 || opt[PF_LL] == 1)
			return (ft_printnwchar(va_arg(*ap, wchar_t), opt));
		return (ft_printnc(va_arg(*ap, int), opt));
	}
	else if ((**format == 'o') && (*format)++)
	{
		if (opt[PF_H] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnoctf((u_short)va_arg(*ap, int), opt));
		if (opt[PF_H] == 1)
			return (ft_printnoct((u_short)va_arg(*ap, int), opt));
		if (opt[PF_HH] == 1 && opt[PF_SHARP] == 1)
			return (ft_printnoctf((u_char)va_arg(*ap, int), opt));
		if (opt[PF_HH] == 1)
			return (ft_printnoct((u_char)va_arg(*ap, int), opt));
		if (opt[PF_SHARP] == 1)
			return (ft_printnoctf(va_arg(*ap, uintptr_t), opt));
		return (ft_printnoct(va_arg(*ap, uintptr_t), opt));
	}
	return (ft_printf_mod2(format, ap, opt));
}
