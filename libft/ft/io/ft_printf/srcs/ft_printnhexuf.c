/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnhexuf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 13:30:42 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/19 13:30:42 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_printnhexuf(uintptr_t p, char *opt)
{
	return (ft_printnhexuf_fd(p, opt, 1));
}
