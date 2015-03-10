#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    shell.jl                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 08:38:20 by mngomane          #+#    #+#              #
#    Updated: 2015/02/12 08:38:20 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

include("commands.jl")
include("shell_colors.jl")
include("tools.jl")

loop = true

while loop
	print(prompt_string())
	entry = readline(STDIN)
	if entry == ""
		loop = false
		println("")
	else
		entry = entry[1:end - 1]
	end
	entry = join(split(entry))
	if entry == "exit()"
		loop = false
	elseif entry == "start()"
		check_return()
	elseif entry != ""
		println(error_prompt())
	end
end
