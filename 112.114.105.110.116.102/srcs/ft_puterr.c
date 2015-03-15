/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 14:43:27 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/15 14:43:27 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterr(char const *s)
{
	return (ft_putstr_fd(s, 2));
}
