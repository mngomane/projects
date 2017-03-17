/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 21:33:06 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/30 21:33:06 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <unistd.h>
# include "../../libfts/include/libfts.h"

# define COREWAR_EXEC_MAGIC		0xea83f3
# define READ_MAX				1000000
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

typedef struct				s_pstring
{
	char					*start;
	char					*end;
}							t_pstring;

typedef struct				s_cmd
{
		t_pstring			*name;
		t_pstring			*comment;
}							t_cmd;

typedef struct				s_instruction
{
	t_pstring				*content;
	struct					s_parameter
	{
		t_pstring			*value;
		enum				s_type
		{
			LABEL,
			REGISTER,
			DIRECT,
			INDIRECT,
			COMMENT
		}					type;
		int					padding;
		struct s_parameter	*next;
	}						*parameter;
	struct s_instruction	*next;
	enum					e_opcode
	{
		NONE,
		LIVE,
		LD,
		ST,
		ADD,
		SUB,
		AND,
		OR,
		XOR,
		ZJMP,
		LDI,
		STI,
		FORK,
		LLD,
		LLDI,
		LFORK,
		AFF
	}						opcode;
	int						padding;
}							t_instruction;

typedef struct				s_file
{
	char					*content;
	void					*pstack[256][256];
	t_cmd					*name;
	t_cmd					*comment;
	t_instruction			*instruct;
	enum					s_syntax
	{
		KO,
		OK
	}						syntax;
	int						padding;
}							t_file;

typedef struct				s_entry
{
	char					*save;
	char					erase[4096];
	t_instruction			*instruct;
	int						fd;
	int						ret_popen;
	int						exit_status;
	char					end;
	char					cjmp;
	char					jpad;
	char					kpad;
}							t_entry;

typedef struct				s_jmp
{
	char					*tmp;
	size_t					wrd;
	size_t					letter[2];
	size_t					i;
	size_t					save;
	size_t					len_word;
}							t_jmp;

void		set_instruction_in_file(t_file **f);
void		set_instruction(t_file **f);
// void		print_file(t_file **f);
void		set_file_cmd(t_file **f, char *cmd);

#endif
