/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 22:36:54 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/23 22:36:54 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>
# include <sys/types.h>

void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
// void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
// void		*ft_memchr(const void *s, int c, size_t n);
// int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memdup(const void *s1, size_t size);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_mtoz(void *src);
void		ft_ztom(void *dst, const size_t size);

#endif
