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
