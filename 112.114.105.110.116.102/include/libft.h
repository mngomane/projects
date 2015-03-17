/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:56:32 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:56:32 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFF_SIZE		32
# define SECURITY		300001
# define FLOOR(x)		(x / 2)
# define CEIL(x)		(x - FLOOR(x))
# define LCAST(x, y)	((x)((y)->content))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_tail(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *s1, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_printf(const char *format, ...);
int					ft_putchar(int c);
int					ft_putchar_fd(int c, int fd);
ssize_t				ft_puthex(uintptr_t p);
ssize_t				ft_puthexf(uintptr_t p);
ssize_t				ft_puthex_fd(uintptr_t p, int fd);
ssize_t				ft_puthexf_fd(uintptr_t p, int fd);
ssize_t				ft_puthexu(uintptr_t p);
ssize_t				ft_puthexu_fd(uintptr_t p, int fd);
ssize_t				ft_putendl(char const *s);
ssize_t				ft_putendl_fd(char const *s, int fd);
ssize_t				ft_puterr(char const *s);
ssize_t				ft_putnbr(int n);
ssize_t				ft_putnbr_fd(int n, int fd);
ssize_t				ft_putnbr_off_t(off_t n);
ssize_t				ft_putnbr_off_t_fd(off_t n, int fd);
ssize_t				ft_putoct(uintptr_t p);
ssize_t				ft_putoct_fd(uintptr_t p, int fd);
ssize_t				ft_putstr(char const *s);
ssize_t				ft_putstr_fd(char const *s, int fd);
ssize_t				ft_putwchar(uintptr_t p);
ssize_t				ft_putwchar_fd(uintptr_t p, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
size_t				ft_strnlen(const char *s, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_ucs2_to_utf8(int ucs2, u_char *utf8);
wchar_t				*ft_wcsdup(const wchar_t *wstr);
size_t				ft_wcslen(const wchar_t *wstr);
wchar_t				*ft_wmemcpy(wchar_t *dst, const wchar_t *src, size_t len);
wchar_t				*ft_wmemmove(wchar_t *dst, const wchar_t *src, size_t len);
wchar_t				*ft_wmemset(wchar_t *wstr, wchar_t c, size_t len);
int					get_next_line(int const fd, char **line);

#endif
