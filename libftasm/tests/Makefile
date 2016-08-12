#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 00:23:38 by mngomane          #+#    #+#              #
#    Updated: 2015/01/28 00:23:38 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = bins/

SRCSDIR = srcs/

LIBDIR = libfts/

NAME = libftasm

SRCS = main.c\
		compare_files.c\
		debug_tests.c\
		debug_tests_part_two.c\
		debug_bonus_part_one.c\
		useless_tests.c\
		bzero_tests.c\
		strcat_tests.c\
		isalpha_tests.c\
		isdigit_tests.c\
		isalnum_tests.c\
		isascii_tests.c\
		isprint_tests.c\
		toupper_tests.c\
		tolower_tests.c\
		strlen_tests.c\
		memset_tests.c\
		memcpy_tests.c\
		strdup_tests.c\
		atoi_tests.c\
		puts_tests.c\
		cat_tests.c


OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall

LIBS = -Llibfts -lfts

INCS = -Iincs -Ilibfts/incs


.PHONY: all clean fclean re check lib

all: $(OBJSDIR) $(NAME) check

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(LIBS) $(INCS) -o $(NAME) $^

$(OBJSDIR):
	mkdir $(OBJSDIR)

check: $(OBJS)
	@$(CC) $(HARDCORESFLAGS) $(LIBS) $(INCS) -o $(NAME) $^

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CXX) $(FLAGS) $(INCS) -c $< -o $@
	@$(CC) $(HARDCORESFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

lib:
	@$(MAKE) -C $(LIBDIR)
	@$(MAKE) re
