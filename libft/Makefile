#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/11 20:33:11 by mngomane          #+#    #+#              #
#    Updated: 2015/03/11 20:33:11 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CTYPE_DIR = ft/ctype/
IO_DIR = ft/io/
PRINTF_DIR = $(addprefix $(IO_DIR), ft_printf/)
GNL_DIR = $(addprefix $(IO_DIR), get_next_line/)
LIB_DIR = ft/lib/
LIST_DIR = ft/list/
MATH_DIR = ft/math/
MEMORY_DIR = ft/memory/
OBJSDIR = bins
STRING_DIR = ft/string/
UNIX_DIR = ft/unix/
WCHAR_DIR = ft/wchar/

NAME = libft.a


.PHONY: all\
		clean\
		fclean\
		re\
		makeobjs\
		nolib\
		ctype\
		io\
		ft_printf\
		get_next_line\
		gnl\
		lib\
		list\
		math\
		memory\
		string\
		unix\
		wchar

all: $(OBJSDIR) makeobjs

$(NAME): $(eval OBJS = $(shell grep -lr . $(OBJSDIR)))
$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

$(OBJSDIR):
	mkdir -pm 0700 $(OBJSDIR)

makeobjs:
	@$(MAKE) -C $(CTYPE_DIR) nolib
	@$(MAKE) -C $(IO_DIR) nolib
	@$(MAKE) -C $(PRINTF_DIR) nolib
	@$(MAKE) -C $(GNL_DIR) nolib
	@$(MAKE) -C $(LIB_DIR) nolib
	@$(MAKE) -C $(LIST_DIR) nolib
	@$(MAKE) -C $(MATH_DIR) nolib
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) -C $(STRING_DIR) nolib
	@$(MAKE) -C $(UNIX_DIR) nolib
	@$(MAKE) -C $(WCHAR_DIR) nolib
	@$(MAKE) $(NAME)

ctype:
	@$(MAKE) -C $(CTYPE_DIR) nolib
	@$(MAKE) $(NAME)

io:
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) -C $(STRING_DIR) nolib
	@$(MAKE) -C $(IO_DIR) nolib
	@$(MAKE) $(NAME)

ft_printf:
	@$(MAKE) -C $(CTYPE_DIR) nolib
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) -C $(STRING_DIR) nolib
	@$(MAKE) -C $(IO_DIR) nolib
	@$(MAKE) -C $(LIB_DIR) nolib
	@$(MAKE) -C $(WCHAR_DIR) nolib
	@$(MAKE) -C $(PRINTF_DIR) nolib
	@$(MAKE) $(NAME)

gnl: get_next_line
get_next_line:
	@$(MAKE) -C $(GNL_DIR) nolib
	@$(MAKE) $(NAME)

lib:
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) -C $(STRING_DIR) nolib
	@$(MAKE) -C $(LIB_DIR) nolib
	@$(MAKE) $(NAME)

list:
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) -C $(LIST_DIR) nolib
	@$(MAKE) $(NAME)

math:
	@$(MAKE) -C $(MATH_DIR) nolib
	@$(MAKE) $(NAME)

memory:
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) $(NAME)

string:
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) -C $(STRING_DIR) nolib
	@$(MAKE) $(NAME)

unix:
	@$(MAKE) -C $(CTYPE_DIR) nolib
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) -C $(STRING_DIR) nolib
	@$(MAKE) -C $(IO_DIR) nolib
	@$(MAKE) -C $(LIB_DIR) nolib
	@$(MAKE) -C $(WCHAR_DIR) nolib
	@$(MAKE) -C $(PRINTF_DIR) nolib
	@$(MAKE) -C $(UNIX_DIR) nolib
	@$(MAKE) $(NAME)

wchar:
	@$(MAKE) -C $(MEMORY_DIR) nolib
	@$(MAKE) -C $(WCHAR_DIR) nolib
	@$(MAKE) $(NAME)


clean:
	@$(MAKE) -C $(CTYPE_DIR) clean
	@$(MAKE) -C $(IO_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(LIST_DIR) clean
	@$(MAKE) -C $(MEMORY_DIR) clean
	@$(MAKE) -C $(STRING_DIR) clean
	@$(MAKE) -C $(UNIX_DIR) clean
	@$(MAKE) -C $(WCHAR_DIR) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
