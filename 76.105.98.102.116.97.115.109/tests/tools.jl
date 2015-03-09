#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    tools.jl                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 08:28:05 by mngomane          #+#    #+#              #
#    Updated: 2015/02/12 08:28:05 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

function	error_string(str)
	string(C_RED, str, C_END)
end

function	valid_string(str)
	string(C_GREEN, str, C_END)
end

function	prompt_string()
	string(C_PURPLE, "jshell ~> ", C_END)
end

function	error_prompt()
	string(C_RED, "[ERROR]~> ", C_END, "Available commands: start, exit")
end
