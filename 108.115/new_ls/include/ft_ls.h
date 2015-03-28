/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 23:34:57 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/26 23:34:57 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_unix.h"

# define LS_NAME		"ft_ls"
# define LS_USAGE		"usage: "LS_NAME" [-Ralrt] [file ...]\n"

typedef struct			s_lut
{
	void				*key;
	void				(*fct)(void);
}						t_lut;

#endif
