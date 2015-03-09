#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/28 15:50:00 by mngomane          #+#    #+#              #
#    Updated: 2014/05/04 20:55:12 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

SRC = main.c\
		sub_main.c\
		string.c\
		list_edit.c\
		initial.c\
		select.c

SRCDIR = srcs/

OBJDIR = bins/

OBJ = $(addprefix $(OBJDIR), $(SRC:%.c=%.o))

CC = cc

FLAGS = -Weverything -Wextra -I incs

TERM = -L/usr/include/ -ltermcap

.PHONY: all clean fclean re


all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(TERM) -o $(NAME) $^

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
