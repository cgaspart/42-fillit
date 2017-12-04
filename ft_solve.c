/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:57:17 by pfournel          #+#    #+#             */
/*   Updated: 2017/11/29 17:33:39 by pfournel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_tetri_count(char *map)
{
	int		nb_tetri;
	int		i;

	i = 0;
	nb_tetri = 0;
	while (map[i])
	{
		if ('A' <= map[i] && map[i] <= 'Z')
			nb_tetri++;
		i++;
	}
	return (nb_tetri / 4);
}

static char	*ft_recursive_solve(char *map, int size, int blocks,
				t_tetri **tetris)
{
	int		i;
	int		n;
	t_tetri	*ptr;

	i = 0;
	n = ft_tetri_count(map);
	ptr = tetris[n];
	while (map[i] && n < blocks)
	{
		if (map[i] == '.' && (ptr = ptr->next))
			if (0 <= (i + ptr->i + size * ptr->j)map[i + ptr->i + size * ptr->j] == '.' && (ptr = ptr->next))
				if (map[i + ptr->i + size * ptr->j] == '.' && (ptr = ptr->next)
						&& map[i + ptr->i + size * ptr->j] == '.')
					return ("YO");
		i++;
	}
	return ("TRISTE");
}

char		*ft_solve(int size, int blocks, t_tetri **tetris)
{
	char	*map;

	if (!(map = ft_mapgen(size)))
		return (NULL);
	while (!(map = ft_recursive_solve(map, size, blocks, tetris)))
	{
		ft_strdel(&map);
		map = ft_mapgen(++size);
	}
	return (map);
}
