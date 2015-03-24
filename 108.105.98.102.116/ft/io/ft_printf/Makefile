#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 22:27:15 by mngomane          #+#    #+#              #
#    Updated: 2015/03/23 22:27:15 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = bins/

SRCSDIR = srcs/

NAME = ../../../libft.a

SRCS = ft_printf.c\
		ft_printf_flags.c\
		ft_printf_modifiers.c\
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
		ft_putwchar.c\
		ft_putwchar_fd.c\
		ft_putwstr.c\
		ft_putwstr_fd.c


OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall -pedantic-errors -std=c89

INCS = -I../../../include

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
