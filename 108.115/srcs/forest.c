/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 23:35:24 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/30 23:35:24 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*entry_type(mode_t mode)
{
	if (S_ISLNK(mode))
		return ("l");
	if (S_ISCHR(mode))
		return ("c");
	if (S_ISFIFO(mode))
		return ("P");
	if (S_ISDIR(mode))
		return ("d");
	if (S_ISBLK(mode))
		return ("b");
	if (S_ISSOCK(mode))
		return ("s");
	return ("-");
}

char		*owner_perm(mode_t mode)
{
	if (!(mode & S_IXUSR) && (mode & S_ISUID))
		return ("S");
	if ((mode & S_IXUSR) && (mode & S_ISUID))
		return ("s");
	if ((mode & S_IXUSR))
		return ("x");
	return ("-");
}

char		*group_perm(mode_t mode)
{
	if (!(mode & S_IXUSR) && (mode & S_ISGID))
		return ("S");
	if ((mode & S_IXUSR) && (mode & S_ISGID))
		return ("s");
	if ((mode & S_IXUSR))
		return ("x");
	return ("-");
}

char		*other_perm(mode_t mode)
{
	if (!(mode & S_IXUSR) && (mode & S_ISVTX))
		return ("T");
	if ((mode & S_IXUSR) && (mode & S_ISVTX))
		return ("t");
	if ((mode & S_IXUSR))
		return ("x");
	return ("-");
}
