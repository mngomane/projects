/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 21:52:51 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/23 21:52:51 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <unistd.h>
# include "ft_string.h"

ssize_t		ft_printchar(char n);
ssize_t		ft_printchar_fd(char n, int fd);
ssize_t		ft_printuchar(u_char n);
ssize_t		ft_printuchar_fd(u_char n, int fd);
int			ft_putchar(int c);
int			ft_putchar_fd(int c, int fd);
ssize_t		ft_puthex(uintptr_t p);
ssize_t		ft_puthexf(uintptr_t p);
ssize_t		ft_puthex_fd(uintptr_t p, int fd);
ssize_t		ft_puthexf_fd(uintptr_t p, int fd);
ssize_t		ft_puthexu(uintptr_t p);
ssize_t		ft_puthexu_fd(uintptr_t p, int fd);
ssize_t		ft_putendl(char const *s);
ssize_t		ft_putendl_fd(char const *s, int fd);
ssize_t		ft_puterr(char const *s);
ssize_t		ft_putlong(long n);
ssize_t		ft_putlong_fd(long n, int fd);
ssize_t		ft_putnchar(int c, size_t rep);
ssize_t		ft_putnchar_fd(int c, size_t rep, int fd);
ssize_t		ft_putnbr(int n);
ssize_t		ft_putnbr_fd(int n, int fd);
ssize_t		ft_putoct(uintptr_t p);
ssize_t		ft_putoct_fd(uintptr_t p, int fd);
ssize_t		ft_putshort(short n);
ssize_t		ft_putshort_fd(short n, int fd);
ssize_t		ft_putstr(char const *s);
ssize_t		ft_putstr_fd(char const *s, int fd);
ssize_t		ft_putulong(u_long n);
ssize_t		ft_putulong_fd(u_long n, int fd);
ssize_t		ft_putushort(u_short n);
ssize_t		ft_putushort_fd(u_short n, int fd);

#endif
