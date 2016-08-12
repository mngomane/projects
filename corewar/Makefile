#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 00:10:37 by mngomane          #+#    #+#              #
#    Updated: 2015/01/20 00:10:37 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ASMDIR = asm_folder/

VMDIR = vm_folder/

TOOLSDIR = tools/


.PHONY: all clean fclean re asm vm

all: asm vm

asm:
	@$(MAKE) -C $(ASMDIR)

vm:
	@$(MAKE) -C $(VMDIR)

clean:
	@$(MAKE) -C $(TOOLSDIR) clean
	@$(MAKE) -C $(ASMDIR) clean
	@$(MAKE) -C $(VMDIR) clean

fclean:
	@$(MAKE) -C $(TOOLSDIR) fclean
	@$(MAKE) -C $(ASMDIR) fclean
	@$(MAKE) -C $(VMDIR) fclean

re: fclean all
