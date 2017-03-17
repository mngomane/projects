/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 00:23:28 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/07 00:23:28 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_pstring			*delcare_t_pstring(void)
{
	t_pstring		*tmp;

	tmp = (t_pstring *)malloc(sizeof(t_pstring));
	if (tmp == NULL)
		return (NULL);
	tmp->start = NULL;
	tmp->end = NULL;
	return (tmp);
}

t_cmd				*declare_t_cmd(void)
{
	t_cmd			*tmp;

	tmp = (t_cmd *)malloc(sizeof(t_cmd));
	if (tmp == NULL)
		return (NULL);
	tmp->name = delcare_t_pstring();
	tmp->comment = delcare_t_pstring();
	return (tmp);
}

struct s_parameter	*declare_s_parameter(void)
{
	struct s_parameter	*tmp;

	tmp = (struct s_parameter *)malloc(sizeof(struct s_parameter));
	if (tmp == NULL)
		return (NULL);
	tmp->value = delcare_t_pstring();
	tmp->type = LABEL;
	tmp->padding = 0;
	tmp->next = NULL;
	return (tmp);
}

t_instruction		*declare_t_instruction(void)
{
	t_instruction	*tmp;

	tmp = (t_instruction *)malloc(sizeof(t_instruction));
	if (tmp == NULL)
		return (NULL);
	tmp->content = delcare_t_pstring();
	tmp->parameter = declare_s_parameter();
	tmp->next = NULL;
	tmp->opcode = NONE;
	tmp->padding = 0;
	return (tmp);
}

t_file				*declare_t_file(void)
{
	t_file		*tmp;
	size_t		column;
	size_t		line;

	column = 0;
	line = 0;
	tmp = (t_file *)malloc(sizeof(t_file));
	if (tmp == NULL)
		return (NULL);
	tmp->content = NULL;
	while (line)
	{
		while (column < 256)
		{
			tmp->pstack[line][column] = NULL;
			++column;
		}
		++line;
	}
	tmp->name = declare_t_cmd();
	tmp->comment = declare_t_cmd();
	tmp->instruct = NULL;
	tmp->syntax = OK;
	tmp->padding = 0;
	return (tmp);
}

t_entry				*declare_t_entry(void)
{
	t_entry		*tmp;

	tmp = (t_entry *)malloc(sizeof(t_entry));
	if (tmp == NULL)
		return (NULL);
	tmp->save = NULL;
	ft_bzero(tmp->erase, 4096);
	tmp->instruct = declare_t_instruction();
	tmp->fd = -1;
	tmp->ret_popen = -1;
	tmp->exit_status = -1;
	tmp->end = '\0';
	tmp->cjmp = '\0';
	tmp->jpad = '\0';
	tmp->kpad = '\0';
	return (tmp);
}

// t_jmp				*declare_t_jmp(void)
// {
// 	t_jmp		*tmp;

// 	tmp = (t_jmp *)malloc(sizeof(t_jmp));
// 	if (tmp == NULL)
// 		return (NULL);
// 	tmp->tmp = NULL;
// 	tmp->wrd = 0;
// 	tmp->letter[0] = 0;
// 	tmp->letter[1] = 0;
// 	tmp->i = 0;
// 	tmp->save = 0;
// 	tmp->len_word = 0;
// 	return (tmp);
// }

t_pstring		*init_pstring(char *start, char *end)
{
	t_pstring	*tmp;

	if ((tmp = delcare_t_pstring()) != NULL)
	{
		tmp->start = start;
		tmp->end = end;
	}
	return (tmp);
}
