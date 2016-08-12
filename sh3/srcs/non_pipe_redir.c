/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_pipe_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 16:43:37 by mngomane          #+#    #+#             */
/*   Updated: 2014/12/28 21:22:00 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "ftsh.h"

void	red_right(t_entry *ent, t_env **envl, t_sent **tab)
{
	if (!tab[1])
		write(2, SH_NL_PARSE, sizeof(SH_NL_PARSE));
	else if (!tab[2])
		write(2, SH_NOT_SUPPORT, sizeof(SH_NOT_SUPPORT));
	else
	{
		if ((ent->pid = fork()) == -1)
			write(2, SH_ERROR, sizeof(SH_ERROR));
		if (!(ent->pid))
		{
			if ((ent->ret_popen = open(tab[2]->word,
				O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
			{
				write(2, SH_ERROR, sizeof(SH_ERROR));
				exit(0);
			}
			dup2(ent->ret_popen, 1);
			ft_son(ent, envl, &tab[1], &(ent->bin));
		}
		else
			ft_father(ent, envl, &(tab[1]));
	}
}

void	red_dright(t_entry *ent, t_env **envl, t_sent **tab)
{
	if (!tab[1])
		write(2, SH_NL_PARSE, sizeof(SH_NL_PARSE));
	else if (!tab[2])
		write(2, SH_NOT_SUPPORT, sizeof(SH_NOT_SUPPORT));
	else
	{
		if ((ent->pid = fork()) == -1)
			write(2, SH_ERROR, sizeof(SH_ERROR));
		if (!(ent->pid))
		{
			if ((ent->ret_popen = open(tab[2]->word,
				O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1)
			{
				write(2, SH_ERROR, sizeof(SH_ERROR));
				exit(0);
			}
			dup2(ent->ret_popen, 1);
			ft_son(ent, envl, &tab[1], &(ent->bin));
		}
		else
			ft_father(ent, envl, &(tab[1]));
	}
}

void	and_tok(t_entry *ent, t_env **envl, t_sent **tab)
{
	if (!tab[1])
		write(2, SH_ERROR, sizeof(SH_ERROR));
	else if (!tab[2])
		write(2, SH_ERROR, sizeof(SH_ERROR));
	else
	{
		if ((ent->pid = fork()) == -1)
			write(2, SH_ERROR, sizeof(SH_ERROR));
		if (!(ent->pid))
			ft_son(ent, envl, &tab[1], &(ent->bin));
		else
			ft_father(ent, envl, &tab[1]);
		if (ent->exit_status == 0)
		{
			if ((ent->pid = fork()) == -1)
				write(2, SH_ERROR, sizeof(SH_ERROR));
			if (!ent->pid)
				ft_son(ent, envl, &tab[2], &(ent->bin));
			else
				ft_father(ent, envl, &tab[2]);
		}
	}
}

void	or_tok(t_entry *ent, t_env **envl, t_sent **tab)
{
	if (!tab[1] || !tab[2])
		write(1, SH_ERROR, sizeof(SH_ERROR));
	else
	{
		if ((ent->pid = fork()) == -1)
			write(2, SH_ERROR, sizeof(SH_ERROR));
		if (!(ent->pid))
			ft_son(ent, envl, &tab[1], &(ent->bin));
		else
			ft_father(ent, envl, &tab[1]);
		if (ent->exit_status != 0)
		{
			if ((ent->pid = fork()) == -1)
				write(2, SH_ERROR, sizeof(SH_ERROR));
			if (!ent->pid)
				ft_son(ent, envl, &tab[2], &(ent->bin));
			else
				ft_father(ent, envl, &tab[2]);
		}
	}
}
