/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 02:09:35 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/20 02:09:35 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_printf_flags4(const char **format, char **opt)
{
	if ((**format == ' ') && ((*opt)[PF_SPACE] = 1))
	{
		(*opt)[PF_SIGN] = ((*opt)[PF_PLUS] == 0 ? ' ' : '+');
		return (1);
	}
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
	else if ((**format == '#') && ((*opt)[PF_SHARP] = 1))
		return (1);
	return (0);
}

static int		ft_printf_flags3(const char **format, char **opt)
{
	size_t		index;

	index = 0;
	(*opt)[PF_DOTC] = '0';
	if ((*opt)[PF_PADC] == 0)
		(*opt)[PF_PADC] = ' ';
	if ((**format == '.') && ((*opt)[PF_DOT] = 1))
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
		return (ft_printf_flags3(format, opt));
	}
	return (ft_printf_flags4(format, opt));
}

static int		ft_printf_flags2(const char **format, char **opt)
{
	if ((**format == 'j') && ((*opt)[PF_J] = 1))
		return (1);
	else if ((**format == 'z') && ((*opt)[PF_Z] = 1))
		return (1);
	else if (**format == 'l')
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

void			ft_printf_flags(const char **format, char **opt)
{
	(*format)++;
	while (ft_printf_flags3(format, opt))
		++(*format);
	while (ft_printf_flags2(format, opt))
		++(*format);
}
