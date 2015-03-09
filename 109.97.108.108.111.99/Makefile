#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 21:45:18 by mngomane          #+#    #+#              #
#    Updated: 2015/03/10 00:21:09 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBDIR = libfts/

OBJSDIR = bins/

SRCSDIR = srcs/

NAME = libft_malloc_$(HOSTTYPE).so

SRCS = malloc.c\
		free.c\
		realloc.c\
		tools.c\
		shared.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall

LIBS = -Llibfts -lfts

INCS = -Iincs -Ilibfts/incs

ifeq ($(origin HOSTTYPE), undefined)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif


.PHONY: all clean fclean re lib

all: lib $(OBJSDIR) $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LIBS) $(INCS) -fpic -shared -o $(NAME) $^
	rm libft_malloc.so
	ln -s $(NAME) libft_malloc.so

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

lib:
	@$(MAKE) -C $(LIBDIR)
