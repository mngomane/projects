/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 23:45:44 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/23 23:45:44 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include "ft_memory.h"

int			ft_wc_to_utf8(wchar_t const wc, u_char *utf8);
wchar_t		*ft_wcscpy(wchar_t *dst, wchar_t const *src);
wchar_t		*ft_wcsdup(wchar_t const *wstr);
size_t		ft_wcslen(wchar_t const *wstr);
wchar_t		*ft_wmemcpy(wchar_t *dst, const wchar_t *src, size_t len);
wchar_t		*ft_wmemmove(wchar_t *dst, const wchar_t *src, size_t len);
wchar_t		*ft_wmemset(wchar_t *wstr, wchar_t c, size_t len);

#endif
