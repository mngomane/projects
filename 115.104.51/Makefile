#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/10 01:02:37 by mngomane          #+#    #+#              #
#    Updated: 2015/03/10 01:02:37 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJSDIR = bins/

SRCSDIR = srcs/

NAME = ft_minishell3

SRCS = main.c\
		bg.c\
		building.c\
		building2.c\
		catch_me.c\
		cd.c\
		dash_cd.c\
		echo.c\
		entry.c\
		error.c\
		father.c\
		father2.c\
		father3.c\
		free_job.c\
		free_list.c\
		imdumb.c\
		inhib.c\
		initial.c\
		job_control.c\
		job_operator.c\
		job_tools.c\
		list_edit.c\
		non_pipe_redir.c\
		non_pipe_redir2.c\
		pars_functions.c\
		pars_functions_redir.c\
		parser.c\
		parser2.c\
		pipe.c\
		setenv.c\
		son.c\
		string.c\
		string2.c\
		sub_init.c\
		sub_main.c\
		sub_main2.c\
		unsetenv.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CXX = gcc

CC = /usr/bin/clang

FLAGS = -Wall -Wextra -Werror

HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall -pedantic-errors -std=c89

INCS = -Iinclude


.PHONY: all clean fclean re check

all: $(OBJSDIR) $(NAME) check

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(INCS) -o $(NAME) $^

$(OBJSDIR):
	mkdir $(OBJSDIR)

check: $(OBJS)
	@$(CC) $(HARDCORESFLAGS) $(INCS) -o $(NAME) $^

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CXX) $(FLAGS) $(INCS) -c $< -o $@
	@$(CC) $(HARDCORESFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
