#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/12 21:20:25 by mngomane          #+#    #+#              #
#    Updated: 2015/03/12 21:20:25 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = bins/

SRCSDIR = srcs/

LIBDIR = libfts/

NAME = expert_system

SRCS = main.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall -pedantic-errors -std=c89

LIB = -Llibfts -lfts

INCS = -Iinclude -Ilibfts/include


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
