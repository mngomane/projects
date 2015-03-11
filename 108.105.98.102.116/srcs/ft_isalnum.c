/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:24:21 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:24:21 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((unsigned char)c >= '0' && (unsigned char)c <= '9')
	{
		return (1);
	}
	if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
	{
		return (1);
	}
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
	{
		return (1);
	}
	return (0);
}
