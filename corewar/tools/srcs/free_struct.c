/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 03:35:01 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/07 03:35:01 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	free_t_pstring(t_pstring **tmp)
{
	free(*tmp);
	*tmp = NULL;
}

void	free_t_cmd(t_cmd **tmp)
{
	if ((*tmp)->name != NULL)
		free_t_pstring(&(*tmp)->name);
	if ((*tmp)->comment != NULL)
		free_t_pstring(&(*tmp)->comment);
	free(*tmp);
	*tmp = NULL;
}

void	free_s_parameter(struct s_parameter **tmp)
{
	struct s_parameter	*prev;

	while (*tmp != NULL)
	{
		prev = *tmp;
		if ((*tmp)->value != NULL)
			free_t_pstring(&(*tmp)->value);
		*tmp = (*tmp)->next;
		free(prev);
	}
}

void	free_t_instruction(t_instruction **tmp)
{
	if ((*tmp)->content != NULL)
		free_t_pstring(&(*tmp)->content);
	if ((*tmp)->parameter != NULL)
		free_s_parameter(&(*tmp)->parameter);
	free(*tmp);
	*tmp = NULL;
}

// void	free_t_file(t_file **tmp)
// {
// 	if ((*tmp)->name != NULL)
// 		free_t_cmd(&(*tmp)->name);
// 	if ((*tmp)->comment != NULL)
// 		free_t_cmd(&(*tmp)->comment);
// 	free(*tmp);
// 	*tmp = NULL;
// }

void	free_t_entry(t_entry **tmp)
{
	if ((*tmp)->instruct != NULL)
		free_t_instruction(&(*tmp)->instruct);
	free(*tmp);
	*tmp = NULL;
}

// void	free_t_jmp(t_jmp **tmp)
// {
// 	free(*tmp);
// 	*tmp = NULL;
// }
