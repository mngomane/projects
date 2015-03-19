#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/11 20:33:11 by mngomane          #+#    #+#              #
#    Updated: 2015/03/11 20:33:11 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = bins/

SRCSDIR = srcs/

NAME =  libftprintf.a

SRCS = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_lstadd.c\
		ft_lstadd_tail.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memdup.c\
		ft_memmove.c\
		ft_memset.c\
		ft_mtoz.c\
		ft_printf.c\
		ft_printchar.c\
		ft_printchar_fd.c\
		ft_printnchar.c\
		ft_printnchar_fd.c\
		ft_printnc.c\
		ft_printnc_fd.c\
		ft_printnhex.c\
		ft_printnhex_fd.c\
		ft_printnhexf.c\
		ft_printnhexf_fd.c\
		ft_printnhexpf.c\
		ft_printnhexpf_fd.c\
		ft_printnhexu.c\
		ft_printnhexu_fd.c\
		ft_printnhexuf.c\
		ft_printnhexuf_fd.c\
		ft_printnint.c\
		ft_printnint_fd.c\
		ft_printnlong.c\
		ft_printnlong_fd.c\
		ft_printnoct.c\
		ft_printnoct_fd.c\
		ft_printnoctf.c\
		ft_printnoctf_fd.c\
		ft_printnshort.c\
		ft_printnshort_fd.c\
		ft_printnstr.c\
		ft_printnstr_fd.c\
		ft_printnuchar.c\
		ft_printnuchar_fd.c\
		ft_printnushort.c\
		ft_printnushort_fd.c\
		ft_printnulong.c\
		ft_printnulong_fd.c\
		ft_printnwchar.c\
		ft_printnwchar_fd.c\
		ft_printnwstr.c\
		ft_printnwstr_fd.c\
		ft_printuchar.c\
		ft_printuchar_fd.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putnchar.c\
		ft_putnchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_puterr.c\
		ft_puthex.c\
		ft_puthex_fd.c\
		ft_puthexf.c\
		ft_puthexf_fd.c\
		ft_puthexu.c\
		ft_puthexu_fd.c\
		ft_putlong.c\
		ft_putlong_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putoct.c\
		ft_putoct_fd.c\
		ft_putshort.c\
		ft_putshort_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_putulong.c\
		ft_putulong_fd.c\
		ft_putushort.c\
		ft_putushort_fd.c\
		ft_putwchar.c\
		ft_putwchar_fd.c\
		ft_putwstr.c\
		ft_putwstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnlen.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_wc_to_utf8.c\
		ft_wcscpy.c\
		ft_wcsdup.c\
		ft_wcslen.c\
		ft_wmemcpy.c\
		ft_wmemmove.c\
		ft_wmemset.c\
		ft_ztom.c\
		get_next_line.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall -pedantic-errors -std=c89

INCS = -Iinclude


.PHONY: all clean fclean re

all: $(OBJSDIR) $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $^
	ranlib $(NAME)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CXX) $(FLAGS) $(INCS) -c $< -o $@
	@$(CC) $(HARDCORESFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
