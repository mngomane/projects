/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:24:28 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/11 20:24:28 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
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
