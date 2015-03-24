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
PRINTF_DIR = $(addprefix $(IO_DIR), ft_printf)
GNL_DIR = $(addprefix $(IO_DIR), get_next_line)
LIB_DIR = ft/lib/
LIST_DIR = ft/list/
MEMORY_DIR = ft/memory/
STRING_DIR = ft/string/
WCHAR_DIR = ft/wchar/

.PHONY: all\
		clean\
		fclean\
		re\
		ctype\
		io\
		ft_printf\
		get_next_line\
		lib\
		list\
		memory\
		string\
		wchar

all: ctype\
		io\
		ft_printf\
		get_next_line\
		lib\
		list\
		memory\
		string\
		wchar

ctype:
	@$(MAKE) -C $(CTYPE_DIR)

io:
	@$(MAKE) -C $(IO_DIR)

ft_printf:
	@$(MAKE) -C $(PRINTF_DIR)

get_next_line:
	@$(MAKE) -C $(GNL_DIR)

lib:
	@$(MAKE) -C $(LIB_DIR)

list:
	@$(MAKE) -C $(LIST_DIR)

memory:
	@$(MAKE) -C $(MEMORY_DIR)

string:
	@$(MAKE) -C $(STRING_DIR)

wchar:
	@$(MAKE) -C $(WCHAR_DIR)


clean:
	@$(MAKE) -C $(CTYPE_DIR) clean
	@$(MAKE) -C $(IO_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(LIST_DIR) clean
	@$(MAKE) -C $(MEMORY_DIR) clean
	@$(MAKE) -C $(STRING_DIR) clean
	@$(MAKE) -C $(WCHAR_DIR) clean

fclean:
	@$(MAKE) -C $(CTYPE_DIR) fclean
	@$(MAKE) -C $(IO_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(MAKE) -C $(LIST_DIR) fclean
	@$(MAKE) -C $(MEMORY_DIR) fclean
	@$(MAKE) -C $(STRING_DIR) fclean
	@$(MAKE) -C $(WCHAR_DIR) fclean

re: fclean all
