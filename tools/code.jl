#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    code.jl                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/13 22:44:39 by mngomane          #+#    #+#              #
#    Updated: 2015/03/13 22:44:39 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

args = length(ARGS)

if	args == 1
	len = length(ARGS[1])

	if len > 0
		print(int(ARGS[1][1]))
	end
	if len > 1
		index = 2;

		while index <= len
			print(string(".", int(ARGS[1][index])))
			index += 1;
		end
	end
	print("\n")
end
