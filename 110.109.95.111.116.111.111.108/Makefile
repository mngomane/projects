#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 08:35:18 by mngomane          #+#    #+#              #
#    Updated: 2015/02/27 08:35:18 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NMDIR = nm/

OTOOLDIR = otool/

TOOLSDIR = tools/


.PHONY: all clean fclean re nm otool

all: nm otool

nm:
	@$(MAKE) -C $(NMDIR)

otool:
	@$(MAKE) -C $(OTOOLDIR)

clean:
	@$(MAKE) -C $(TOOLSDIR) clean
	@$(MAKE) -C $(NMDIR) clean
	@$(MAKE) -C $(OTOOLDIR) clean

fclean:
	@$(MAKE) -C $(TOOLSDIR) clean
	@$(MAKE) -C $(NMDIR) fclean
	@$(MAKE) -C $(OTOOLDIR) fclean

re: fclean all
