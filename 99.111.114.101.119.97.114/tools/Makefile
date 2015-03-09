#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 01:10:08 by mngomane          #+#    #+#              #
#    Updated: 2015/02/02 01:10:08 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = bins/

SRCSDIR = srcs/

NAME = run

SRCS = edit_list.c\
		free_list.c\
		entry.c\
		pstrings.c\
		init_struct.c\
		free_struct.c\
		print_list.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall

INCS = -Iincs


.PHONY: all clean re

all: $(OBJSDIR) $(NAME)

$(NAME): $(OBJS)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CXX) $(FLAGS) $(INCS) -c $< -o $@
	@$(CC) $(HARDCORESFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJS)

re: clean all
