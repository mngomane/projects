#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    decode.jl                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/13 22:44:33 by mngomane          #+#    #+#              #
#    Updated: 2015/03/13 22:44:33 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

args = length(ARGS)

if	args == 1
	index = 1;

	tab = split(ARGS[1], ".")
	len = length(tab)
	while index <= len
		print(char(int(tab[index])))
		index += 1
	end
	print("\n")
end
