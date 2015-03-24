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

#include "ft_printf.h"

static ssize_t	analyse_format(const char **format, va_list *ap, char **opt)
{
	ssize_t		ret;
	ssize_t		tmp;
	ssize_t		cmp;

	cmp = 0;
	tmp = 0;
	ret = 0;
	while (**format)
	{
		if (**format == '%')
		{
			ft_printf_flags(format, opt);
			tmp = ft_printf_mod(format, ap, *opt);
			cmp = (ssize_t)ft_mtoz(*opt + PF_PREC) - tmp;
			if (((*opt)[PF_MINUS] == 1) && (cmp > 0))
				ret += ft_putnchar((*opt)[PF_PADC], (size_t)cmp);
			ret += tmp;
		}
		else
			ret += (**format ? write(1, (*format)++, 1) : 0);
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*opt;
	ssize_t		ret;

	opt = ft_memalloc(256 * sizeof(char));
	va_start(ap, format);
	ret = analyse_format(&format, &ap, &opt);
	va_end(ap);
	free(opt);
	return ((int)ret);
}
