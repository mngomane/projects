#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 21:25:14 by mngomane          #+#    #+#              #
#    Updated: 2015/03/23 21:25:14 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = bins/

SRCSDIR = srcs/

NAME = ../../libft.a

SRCS = ft_printchar.c\
		ft_printchar_fd.c\
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
		ft_putushort_fd.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall -pedantic-errors -std=c89

INCS = -I../../include


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
