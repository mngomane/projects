/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 23:54:02 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/19 23:54:02 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "../../tools/include/tools.h"

#include <fcntl.h>
#include <stdio.h>

int			main(int ac, char **av)
{
	t_entry		*entry;
	t_file		*file;
	t_instruction	*saved_i;
	struct s_parameter	*saved_p;

	saved_i = NULL;
	saved_p = NULL;
	entry = declare_t_entry();
	if (ac == 1)
	{
		ft_putstr("Usage: ./asm [-a] <sourcefile.s>\n    -a : Instead of");
		ft_putstr(" creating a .cor file, outputs a stripped and");
		ft_putstr(" annotated version of the code to the standard output\n");
	}
	else
	{
		entry->fd = open(av[1], O_RDONLY);
		if (entry->fd == -1)
		{
			ft_putstr("Can't read source file ");
			ft_puts(av[1]);
			return (-1);
		}
		fill_entry(entry);
		close(entry->fd);
		file = declare_t_file();
		file->content = entry->save;
		set_instruction_in_file(&file);
		saved_i = file->instruct;
		while (file->instruct && file->syntax == OK)
		{
			saved_p	= file->instruct->parameter;
			set_instruction(&file);
			while (file->instruct->parameter)
				file->instruct->parameter = file->instruct->parameter->next;
			file->instruct->parameter = saved_p;
			file->instruct = file->instruct->next;
		}
		file->instruct = saved_i;
		set_file_cmd(&file, NAME_CMD_STRING);
		set_file_cmd(&file, COMMENT_CMD_STRING);
		if (file->syntax == OK)
			ft_puts("The file is valid!");
		else
			ft_puts("Error");
	}
	free_t_entry(&entry);
	return (0);
}
