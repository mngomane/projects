/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 08:34:39 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/02 08:34:39 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	compare_char(FILE *fp1, FILE *fp2)
{
	int		ch1;
	int		ch2;
	int		result;

	result = OK;
	ch1 = getc(fp1);
	ch2 = getc(fp2);
	while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2))
	{
		ch1 = getc(fp1);
		ch2 = getc(fp2);
	}
	if (ch1 == ch2)
		result = OK;
	else if (ch1 != ch2)
		result = KO;
	fclose(fp1);
	fclose(fp2);
	return (result);
}

int			compare_files(char *fname1, char *fname2)
{
	FILE	*fp1;
	FILE	*fp2;

	if ((fp1 = fopen(fname1, "r")) == NULL)
		return (KO);
	if ((fp2 = fopen(fname2, "r")) == NULL) {
		fclose(fp1);
		return (KO);
	}
	return (compare_char(fp1, fp2));
}
