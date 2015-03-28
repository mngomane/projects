/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 23:52:40 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/23 23:52:40 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# define I	(index[0])
# define J	(index[1])

# include "ft_string.h"

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void		msort_int_tab(int *tab, size_t size, int (*cmp)(int, int));
void		qsort_int_tab(int *tab, size_t size, int (*cmp)(int, int));

#endif
