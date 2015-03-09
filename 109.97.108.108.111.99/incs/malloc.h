/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 07:31:26 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/19 07:31:26 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <sys/types.h>
# include <unistd.h>
# include "../libfts/incs/libfts.h"

# define NODE_TYPE		0
# define AREA_TYPE		1
# define AREA_STATE		2
# define AREA_FSTATE	3
# define AREA_SIZE		8
# define AREA_PREV		16
# define AREA_NEXT		24
# define DATA_START		32
# define BACK_TYPE		1
# define BACK_STATE		2
# define BACK_INDEX		3
# define N_SIZE			16
# define M_SIZE			512
# define NBR_TO_PTR(x)	(t_area)(uintptr_t)x
# define NBR_TO_CHAR(x)	(u_char)(uintptr_t)x
# define HEAD_PTR(x)	(t_area)((char *)x - 35)
# define SIZE_PTR(x)	(t_area)((char *)x - 27)
# define PREV_PTR(x)	(t_area)((char *)x - 19)
# define NEXT_PTR(x)	(t_area)((char *)x - 11)
# define NEXT(x)		(x ? x + AREA_NEXT : (t_area)0)
# define CHAR_CAST(x)	(u_char)x

typedef u_char			*t_area;

extern t_area			g_area;

char					*find_available_space(t_area *address, size_t size,
												char needle);
size_t					ft_btos(t_area *address);
size_t					ft_get_right_size(size_t size);
t_area					find_mblock(t_area *address, char needle);
void					show_alloc_mem(void);
void					free(void *ptr);
void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					add_node(t_area *address, char needle, size_t size);
void					ft_stob(t_area *address, const size_t size);
void					ft_putnbr_hex(uintptr_t p);

#endif
