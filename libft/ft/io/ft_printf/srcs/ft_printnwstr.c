/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnwstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 01:53:37 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 01:53:37 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_printnwstr(wchar_t const *wstr, char *opt)
{
	return (ft_printnwstr_fd(wstr, opt, 1));
}
