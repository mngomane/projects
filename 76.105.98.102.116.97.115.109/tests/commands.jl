#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    run_command.jl                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 07:32:54 by mngomane          #+#    #+#              #
#    Updated: 2015/02/12 07:32:54 by mngomane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

function	run_command(cmd, arg)
	try
		run(`$cmd $arg`)
	end
end

function	tests_state(data)
	state = true
	data = split(data, '\n', false)
	for c in data
		try
			if c[end-3:end] != "[OK]"
				println("reached")
				state = false
			end
		end
	end
	return state
end

function	check_return()
	originalSTDOUT = STDOUT
	(outRead, outWrite) = redirect_stdout()
	run(`./libftasm`)
	close(outWrite)
	data = readavailable(outRead)
	redirect_stdout(originalSTDOUT)
	if tests_state(data) == true
		println(valid_string("OK"))
	else
		println(error_string("KO"))
	end
end
