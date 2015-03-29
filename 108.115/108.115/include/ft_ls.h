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

# include <dirent.h>
# include "libft.h"

# define BIN_NAME		"ft_ls"
# define BIN_USAGE		"usage: "BIN_NAME" [-Ralrt] [file ...]\n"

# define F_RECURSIVE(x)	(x & 0x01)
# define F_ALL(x)		(x & 0x02)
# define F_LONG(x)		(x & 0x04)
# define F_REVERSE(x)	(x & 0x08)
# define F_TIME(x)		(x & 0x10)



typedef struct			s_lut
{
	void				*key;
	void				(*fct)(void *, void *);
}						t_lut;

typedef struct			s_file
{
	DIR					*dirp;
	void				*path;
	void				*name;
	void				*type;
}						t_file;

int						get_options(int *ac, char ***av, void *flags);

#endif
