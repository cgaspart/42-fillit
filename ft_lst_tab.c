/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:02:51 by pfournel          #+#    #+#             */
/*   Updated: 2017/12/06 17:35:22 by pfournel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*ft_lst_alloc(void)
{
	t_tetri	*tetris;

	if (!(tetris = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tetris->i1 = 0;
	tetris->j1 = 0;
	tetris->i2 = 42;
	tetris->i3 = 42;
	tetris->i4 = 42;
	tetris->next = NULL;
	return (tetris);
}

static void		ft_lst_infos(t_tetri *tetris, int x, int y)
{
	if (tetris->i2 == 42)
	{
		tetris->i2 = x;
		tetris->j2 = y;
	}
	else if (tetris->i3 == 42)
	{
		tetris->i3 = x;
		tetris->j3 = y;
	}
	else
	{
		tetris->i4 = x;
		tetris->j4 = y;
	}
}

static t_tetri	*ft_tetri_lst(char *fcontent, int x, int y, t_tetri *tetris)
{
	fcontent[x + (5 * y)] = '*';
	if (!x && !y)
	{
		if (!(tetris = ft_lst_alloc()))
			return (NULL);
	}
	else
		ft_lst_infos(tetris, x, y);
	if (fcontent[x + (5 * y) + 1] == '#')
		if (!(tetris = ft_tetri_lst(fcontent, x + 1, y, tetris)))
			return (NULL);
	if (fcontent[x + (5 * y) - 1] == '#')
		if (!(tetris = ft_tetri_lst(fcontent, x - 1, y, tetris)))
			return (NULL);
	if (x + (5 * y) + 5 < (int)ft_strlen &&
	!(fcontent[x + (5 * y) + 1] == '\n' && fcontent[x + (5 * y) + 2] == '\n') &&
	!(fcontent[x + (5 * y) + 2] == '\n' && fcontent[x + (5 * y) + 3] == '\n') &&
	!(fcontent[x + (5 * y) + 3] == '\n' && fcontent[x + (5 * y) + 4] == '\n') &&
	fcontent[x + (5 * y) + 5] == '#')
		if (!(tetris = ft_tetri_lst(fcontent, x, y + 1, tetris)))
			return (NULL);
	return (tetris);
}

t_tetri			*ft_lst_tab(char *fcontent)
{
	t_tetri	*tetris;
	t_tetri	*ptr;
	int		i;

	tetris = NULL;
	i = 0;
	while (fcontent[i])
	{
		while (fcontent[i] != '#')
			i++;
		if (!tetris)
		{
			if (!(tetris = ft_tetri_lst(&(fcontent[i]), 0, 0, ptr)))
				return (NULL);
			ptr = tetris;
		}
		else if (!(ptr->next = ft_tetri_lst(&(fcontent[i]), 0, 0, ptr->next)))
			return (NULL);
		while (fcontent[i] && !(fcontent[i] == '\n' && fcontent[i + 1] == '\n'))
			i++;
		if (ptr->next)
			ptr = ptr->next;
	}
	return (tetris);
}
