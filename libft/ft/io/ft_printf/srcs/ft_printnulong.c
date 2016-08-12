/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnulong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 22:03:38 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/18 22:03:38 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_printnulong(u_long n, char *opt)
{
	return (ft_printnulong_fd(n, opt, 1));
}
