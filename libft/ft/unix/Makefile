#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 09:23:39 by mngomane          #+#    #+#              #
#    Updated: 2015/03/27 09:23:39 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = ../../bins/

SRCSDIR = srcs/

NAME = ../../libft.a

SRCS = $(notdir $(shell grep -rl . $(SRCSDIR)))

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall -pedantic-errors -std=c89

INCS = -I../../include


.PHONY: all clean fclean re nolib

all: $(OBJSDIR) $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

nolib: $(OBJSDIR) $(OBJS)

$(OBJSDIR):
	mkdir -pm 0700 $(OBJSDIR)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CXX) $(FLAGS) $(INCS) -c $< -o $@
	@$(CC) $(HARDCORESFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
