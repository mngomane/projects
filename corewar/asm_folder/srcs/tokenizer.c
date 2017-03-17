/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 00:21:32 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/02 00:21:32 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "../../tools/include/tools.h"


#include <stdio.h>

// static int	is_opcode(const char *start, const char *end)
// {
// 	char	*op_tab[2][16];
// 	int		index;

// 	index = 0;
// 	op_tab[0][0] = "live";
// 	op_tab[0][1] = "ld";
// 	op_tab[0][2] = "st";
// 	op_tab[0][3] = "add";
// 	op_tab[0][4] = "sub";
// 	op_tab[0][5] = "and";
// 	op_tab[0][6] = "or";
// 	op_tab[0][7] = "xor";
// 	op_tab[0][8] = "zjmp";
// 	op_tab[0][9] = "ldi";
// 	op_tab[0][10] = "sti";
// 	op_tab[0][11] = "fork";
// 	op_tab[0][12] = "lld";
// 	op_tab[0][13] = "lldi";
// 	op_tab[0][14] = "lfork";
// 	op_tab[0][15] = "aff";
// 	while (index < 16)
// 	{
// 		op_tab[1][index] = op_tab[0][index] + ft_strlen(op_tab[0][index]);
// 		if (!ft_pstrcmp(start, end, op_tab[0][index], op_tab[1][index]))
// 			return (1);
// 		++index;
// 	}
// 	return (0);
// }

// static int	is_direct(const char *start)
// {
// 	return ((*start == '%') ? 1 : 0);
// }

// static int	is_label(const char *start)
// {
// 	return ((*start == ':') ? 1 : 0);
// }

// static int	is_valid_label(const char c)
// {
// 	char	*iterator;
// 	// char	*start;
// 	// char	*end;

// 	// start = LABEL_CHARS;
// 	// end = start + ft_strlen(start) + 1;
// 	iterator = LABEL_CHARS;
// 	while (iterator != (LABEL_CHARS + ft_strlen(LABEL_CHARS) + 1))
// 	{
// 		if (c == *iterator)
// 			return (1);
// 		++iterator;
// 	}
// 	return (0);
// }


// static void		apply_on_parameter(struct s_parameter **i, void (*function)(struct s_parameter **))
// {
// 	struct s_parameter	*save;

// 	save = *i;
// 	while (*i)
// 	{
// 		function(i);
// 		*i = (*i)->next;
// 	}
// 	*i = save;
// }

// static void		clear(struct s_parameter **i)
// {
// 	if (*((*i)->value->end - 1) == SEPARATOR_CHAR)
// 		--(*i)->value->end;
// }

// static void		set_elem(t_instruction **i)
// {
// 	char		*start[2];
// 	char		*end[2];

// 	start[0] = NAME_CMD_STRING;
// 	start[1] = COMMENT_CMD_STRING;
// 	end[0] = start[0] + ft_strlen(start[0]);
// 	end[1] = start[1] + ft_strlen(start[1]);
// 	if (!ft_pstrcmp((char *)(*i)->parent->start, (char *)(*i)->parent->end, start[0], end[0]))
// 		(*i)->elem = CMD_NAME;
// 	else if (!ft_pstrcmp((char *)(*i)->parent->start, (char *)(*i)->parent->end, start[1], end[1]))
// 		(*i)->elem = CMD_COMMENT;
// 	else if (is_opcode((char *)(*i)->parent->start, (char *)(*i)->parent->end))
// 		(*i)->elem = OPCODE;
// 	else
// 		(*i)->elem = NONE;
// 	printf("\nset_tokens - token: %d | start: %c | end: %c\n", (*i)->elem, *(*i)->parent->start, *((*i)->parent->end - 1));
// }

// static void		set_type(t_instruction **i)
// {
// 	if (is_direct((*i)->parent->start))
// 		++(*i)->parent->start;
// 	if (is_label((*i)->parent->start))
// 		++(*i)->parent->start;
// }

void			set_instruction_in_file(t_file **f)
{
	char		*iterator;
	char		*start;
	char		*end;

	iterator = (*f)->content;
	while (*iterator != '\0')
	{
		start = iterator;
		while (*iterator != '\n' && *iterator != '\0')
			++iterator;
		end = iterator;
		link_instruction(&((*f)->instruct), start, end);
		++iterator;
	}
}

static void		set_ends(char *iterator, char *end1, char *end2)
{
	if (*iterator == '"')
	{
		*end1 = '"';
		*end2 = '"';
	}
	if (*iterator == COMMENT_CHAR || *iterator == ';')
	{
		*end1 = '\0';
		*end2 = '\n';
	}
}

static int		set_start_end(char **i, char **start, char **end, char *p_end)
{
	char		end1;
	char		end2;

	(void)end;
	end1 = ' ';
	end2 = '\t';
	set_ends(*i, &end1, &end2);
	*start = *i;
	*i += ((**i == '"') ? 1 : 0);
	while (*i != p_end && **i != end1 && **i != end2)
		++(*i);
	*end = *i;
	if (end1 == '"')
	{
		if (**i != '"')
			return (-1);
		else
		{
			++(*i);
			++(*start);
		}
	}
	return (0);
}

void			set_instruction(t_file **f)
{
	char		*iterator;
	char		*master_end;
	char		*start;
	char		*end;

	start = NULL;
	end = NULL;
	master_end = (*f)->instruct->content->end;
	iterator = (*f)->instruct->content->start;
	while (iterator != master_end)
	{
		if (set_start_end(&iterator, &start, &end, master_end) == -1)
			(*f)->syntax = KO;
		if (start != end)
			link_param(&((*f)->instruct->parameter), start, end);
		while (*iterator == ' ' || *iterator == '\t')
			++iterator;
	}
}

void			set_file_cmd(t_file **f, char *cmd)
{
	t_instruction		*saved_i;
	struct s_parameter	*saved_p;
	struct s_parameter	*parameter;
	char				*st;
	char				*nd;

	saved_i = (*f)->instruct;
	while ((*f)->instruct)
	{
		saved_p = (*f)->instruct->parameter;
		while ((*f)->instruct->parameter)
		{
			st = (*f)->instruct->parameter->value->start;
			nd = (*f)->instruct->parameter->value->end;
			if ((st != nd) && !ft_pstrcmp(st, nd, cmd, ft_pstrend(cmd)))
			{
				(*f)->instruct->parameter = (*f)->instruct->parameter->next;
				parameter = (*f)->instruct->parameter;
				(*f)->name->name = init_pstring(parameter->value->start,
					parameter->value->end);
				parameter = saved_p;
				(*f)->instruct = saved_i;
				return;
			}
			(*f)->instruct->parameter = (*f)->instruct->parameter->next;
		}
		(*f)->instruct->parameter = saved_p;
		(*f)->instruct = (*f)->instruct->next;
	}
	(*f)->instruct = saved_i;
	(*f)->syntax = KO;
}

// void			print_file(t_file **f)
// {
// 	t_instruction		*save;
// 	struct s_parameter	*saved_p;

// 	save = (*f)->instruct;
// 	while ((*f)->instruct)
// 	{
// 		ft_putstr("file->instruction->content: ");
// 		putpstr((*f)->instruct->content);
// 		ft_puts("");
// 		saved_p = (*f)->instruct->parameter;
// 		while ((*f)->instruct->parameter)
// 		{
// 			ft_putstr("file->instruction->parameter->value: ");
// 			putpstr((*f)->instruct->parameter->value);
// 			ft_puts("");
// 			(*f)->instruct->parameter = (*f)->instruct->parameter->next;
// 		}
// 		(*f)->instruct->parameter = saved_p;
// 		(*f)->instruct = (*f)->instruct->next;
// 	}
// 	(*f)->instruct = save;
// }
