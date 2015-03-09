/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 04:00:24 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/02 04:00:24 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"

// void	free_instruction(t_instruction **i)
// {
// 	t_instruction	*save;

// 	save = *i;
// 	while (*i)
// 	{
// 		if ((*i)->word)
// 			free((*i)->word);
// 		(*i)->word = NULL;
// 		*i = (*i)->next;
// 	}
// 	*i = save;
// 	while (*i)
// 	{
// 		free(*i);
// 		*i = (*i)->next;
// 	}
// }

// void	free_line(t_line **line)
// {
// 	while (*line)
// 	{
// 		free(*line);
// 		*line = (*line)->next;
// 	}
// }
