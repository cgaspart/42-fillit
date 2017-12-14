/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htag_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:06:33 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/07 16:27:44 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_count(char *fcontent, int i)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (j < 20)
	{
		if (fcontent[i + j] == '#')
			count++;
		if (fcontent[i + j] == '\0')
			return (0);
		j++;
	}
	if (count == 4)
		return (1);
	else
		return (0);
}

int			ft_htag_count(char *fcontent)
{
	int i;

	i = 0;
	while (fcontent[i] != '\0')
	{
		if (ft_count(fcontent, i))
		{
			i = i + 20;
			if (!fcontent[i])
				return (1);
			i++;
		}
		else
			return (0);
	}
	return (1);
}
