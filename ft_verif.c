/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:23:10 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/27 12:25:13 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_verif_line(char *fcontent, int i)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (fcontent[i + j] != '#' && fcontent[i + j] != '.')
			return (0);
		j++;
	}
	if (fcontent[i + j] == '\n')
		return (1);
	else
		return (0);
}

static int		ft_block_checker(char *fcontent, int i)
{
	if (fcontent[i] == '\n' && (fcontent[i + 1] == '.'
				|| fcontent[i + 1] == '#'))
		return (2);
	else if (fcontent[i] == '\0')
		return (1);
	else
		return (0);
}

static int		ft_verif_block(char *fcontent)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (fcontent[i] != '\0')
	{
		if (!ft_verif_line(fcontent, i))
			return (0);
		i = i + 5;
		line++;
		if (line == 4)
		{
			line = 0;
			if (ft_block_checker(fcontent, i) == 2)
				i++;
			else if (ft_block_checker(fcontent, i) == 1)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

static int		ft_verif_char(char *fcontent)
{
	int i;

	i = 0;
	while (fcontent[i] != '\0')
	{
		if (fcontent[i] != '#' && fcontent[i] != '.' && fcontent[i] != '\n')
			return (0);
		i++;
	}
	return (ft_verif_block(fcontent));
}

int				ft_verif(char *fcontent)
{
	if (ft_verif_char(fcontent) && ft_htag_count(fcontent))
		return (1);
	return (0);
}
