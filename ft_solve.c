/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:57:17 by pfournel          #+#    #+#             */
/*   Updated: 2017/12/07 13:53:56 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_writemap(char *map, char piece, t_tetri *tetris, int size)
{
	map[0] = piece;
	map[tetris->i2 + tetris->j2 * size] = piece;
	map[tetris->i3 + tetris->j3 * size] = piece;
	map[tetris->i4 + tetris->j4 * size] = piece;
}

static char	*ft_recursive_solve(char *map, int size, char piece, t_tetri *tet)
{
	int		i;
	int		maplen;

	i = 0;
	maplen = (int)ft_strlen(map);
	while (map[i])
	{
		if (map[i] == '.' && (i + tet->i2 + tet->j2 * size) < maplen &&
				map[i + tet->i2 + tet->j2 * size] == '.' &&
				(i + tet->i3 + tet->j3 * size) < maplen &&
				map[i + tet->i3 + tet->j3 * size] == '.' &&
				(i + tet->i4 + tet->j4 * size) < maplen &&
				map[i + tet->i4 + tet->j4 * size] == '.')
		{
			ft_writemap(&(map[i]), piece, tet, size);
			if (!tet->next ||
					ft_recursive_solve(map, size, piece + 1, tet->next))
				return (map);
			ft_writemap(&(map[i]), '.', tet, size);
		}
		i++;
	}
	return (NULL);
}

char		*ft_solve(int size, int blocks, t_tetri *tetris)
{
	char	*map;

	if (!blocks || !tetris)
		return (NULL);
	if (!(map = ft_mapgen(size)))
		return (NULL);
	while (!(map = ft_recursive_solve(map, size + 1, 'A', tetris)))
		map = ft_mapgen(++size);
	return (map);
}
