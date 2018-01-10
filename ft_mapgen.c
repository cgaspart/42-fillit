/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:45:47 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/29 15:24:09 by pfournel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_mapgen(int nb)
{
	int		y;
	int		x;
	int		i;
	char	*str;

	y = 0;
	i = 0;
	str = malloc(sizeof(char) * (nb * nb + nb + 1));
	while (y < nb)
	{
		x = 0;
		while (x < nb)
		{
			str[i] = '.';
			x++;
			i++;
		}
		str[i] = '\n';
		i++;
		y++;
	}
	str[i] = '\0';
	return (str);
}
