/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htag_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:06:33 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/27 15:21:08 by cgaspart         ###   ########.fr       */
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
	int count;

	i = 0;
	count = 0;
	while (fcontent[i] != '\0')
	{
		if (ft_count(fcontent, i))
			i = i + 21;
		else
			return (0);
	}
	return (1);
}
