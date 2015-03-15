#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/10 04:09:10 by mngomane          #+#    #+#              #
#    Updated: 2015/03/10 04:09:10 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = bins/

SRCSDIR = srcs/

LIBDIR = libft/

NAME = ft_ls

SRCS = main.c\
		no_arg.c\
		l_arg.c\
		no_file.c\
		no_lfile.c\
		no_afile.c\
		no_ofile.c\
		illegal.c\
		list_edit.c\
		apply.c\
		sub_main.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall -pedantic-errors -std=c89

LIB = -Llibft -lft

INCS = -Iinclude -Ilibft/include


.PHONY: all clean fclean re check

all: $(OBJSDIR) $(NAME) check

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBDIR)
	$(CXX) $(FLAGS) $(LIB) $(INCS) -o $(NAME) $^

$(OBJSDIR):
	mkdir $(OBJSDIR)

check: $(OBJS)
	@$(CC) $(HARDCORESFLAGS) $(LIB) $(INCS) -o $(NAME) $^

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CXX) $(FLAGS) $(INCS) -c $< -o $@
	@$(CC) $(HARDCORESFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
