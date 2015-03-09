#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 23:54:36 by mngomane          #+#    #+#              #
#    Updated: 2015/01/19 23:54:36 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBDIR = ../libfts/

OBJSDIR = bins/

SRCSDIR = srcs/

TOOLSDIR = ../tools/

NAME = ../asm

SRCS = main.c\
		tokenizer.c

TOOLSSRCS = edit_list.c\
			free_list.c\
			entry.c\
			pstrings.c\
			init_struct.c\
			free_struct.c\
			print_list.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

TOOLSOBJS = $(addprefix $(addprefix $(TOOLSDIR), $(OBJSDIR)), $(TOOLSSRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall

LIBS = -L../libfts -lfts

INCS = -Iincs -I../libfts/incs -I../tools/incs


.PHONY: all clean fclean re check lib

all: lib $(OBJSDIR) $(NAME) check

$(NAME): $(OBJS) $(TOOLSOBJS)
	$(CXX) $(FLAGS) $(LIBS) $(INCS) -o $(NAME) $^

$(OBJSDIR):
	mkdir $(OBJSDIR)

check: $(OBJS) $(TOOLSOBJS)
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
	@$(MAKE) -C $(TOOLSDIR)
