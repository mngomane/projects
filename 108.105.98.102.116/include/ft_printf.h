/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 22:12:59 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/23 22:12:59 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "ft_ctype.h"
# include "ft_io.h"
# include "ft_lib.h"
# include "ft_memory.h"
# include "ft_wchar.h"

# define PF_SHARP		0
# define PF_ZERO		1
# define PF_MINUS		2
# define PF_PLUS		3
# define PF_SPACE		4
# define PF_DOT			5
# define PF_J			6
# define PF_Z			7
# define PF_L			8
# define PF_LL			9
# define PF_H			10
# define PF_HH			11
# define PF_PREC		12
# define PF_PERIOD		20
# define PF_PADC		28
# define PF_DOTC		29
# define PF_SIGN		30
# define PF_TMPP		31
# define PF_TMP			42

int			ft_printf(const char *format, ...);
void		ft_printf_flags(const char **format, char **opt);
ssize_t		ft_printf_mod(const char **format, va_list *ap, char *opt);
ssize_t		ft_printnc(int c, char *opt);
ssize_t		ft_printnc_fd(int c, char *opt, int fd);
ssize_t		ft_printnchar(char n, char *opt);
ssize_t		ft_printnchar_fd(char n, char *opt, int fd);
ssize_t		ft_printnhex(uintptr_t p, char *opt);
ssize_t		ft_printnhex_fd(uintptr_t p, char *o, int fd);
ssize_t		ft_printnhexf(uintptr_t p, char *opt);
ssize_t		ft_printnhexf_fd(uintptr_t p, char *opt, int fd);
ssize_t		ft_printnhexpf(uintptr_t p, char *opt);
ssize_t		ft_printnhexpf_fd(uintptr_t p, char *opt, int fd);
ssize_t		ft_printnhexu(uintptr_t p, char *opt);
ssize_t		ft_printnhexu_fd(uintptr_t p, char *opt, int fd);
ssize_t		ft_printnhexuf(uintptr_t p, char *opt);
ssize_t		ft_printnhexuf_fd(uintptr_t p, char *opt, int fd);
ssize_t		ft_printnint(int n, char *opt);
ssize_t		ft_printnint_fd(int n, char *opt, int fd);
ssize_t		ft_printnlong(long n, char *opt);
ssize_t		ft_printnlong_fd(long n, char *opt, int fd);
ssize_t		ft_printnoct(uintptr_t p, char *opt);
ssize_t		ft_printnoct_fd(uintptr_t p, char *opt, int fd);
ssize_t		ft_printnoctf(uintptr_t p, char *opt);
ssize_t		ft_printnoctf_fd(uintptr_t p, char *opt, int fd);
ssize_t		ft_printnshort(short n, char *opt);
ssize_t		ft_printnshort_fd(short n, char *opt, int fd);
ssize_t		ft_printnstr(char const *str, char *opt);
ssize_t		ft_printnstr_fd(char const *s, char *opt, int fd);
ssize_t		ft_printnuchar(u_char n, char *opt);
ssize_t		ft_printnuchar_fd(u_char n, char *opt, int fd);
ssize_t		ft_printnulong(u_long n, char *opt);
ssize_t		ft_printnulong_fd(u_long n, char *opt, int fd);
ssize_t		ft_printnushort(u_short n, char *opt);
ssize_t		ft_printnushort_fd(u_short n, char *opt, int fd);
ssize_t		ft_printnwchar(wchar_t const wc, char *opt);
ssize_t		ft_printnwchar_fd(wchar_t const c, char *opt, int fd);
ssize_t		ft_printnwstr(wchar_t const *wstr, char *opt);
ssize_t		ft_printnwstr_fd(wchar_t const *s, char *opt, int fd);
ssize_t		ft_putwchar(wchar_t const wc);
ssize_t		ft_putwchar_fd(wchar_t const wc, int fd);
ssize_t		ft_putwstr(wchar_t const *wstr);
ssize_t		ft_putwstr_fd(wchar_t const *wstr, int fd);

#endif
