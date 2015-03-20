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
			ft_printf_flags(&format, &opt);
			tmp = ft_printf_mod(&format, &ap, opt);
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
