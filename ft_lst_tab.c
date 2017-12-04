/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:02:51 by pfournel          #+#    #+#             */
/*   Updated: 2017/11/30 18:19:04 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*ft_lst_alloc(char *copy, int x, int y)
{
	t_tetri	*tetris;

	copy[x + (5 * y)] = '*';
	if (!(tetris = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tetris->i = x;
	tetris->j = y;
	tetris->next = NULL;
	return (tetris);
}

static t_tetri	*ft_tetri_lst(char *copy, int i, int x, int y)
{
	t_tetri	*tetris;
	t_tetri	*ptr;

	if (!(tetris = ft_lst_alloc(&(copy[i]), x, y)))
		return (NULL);
	ptr = tetris;
	if (copy[i + x + (5 * y) + 1] == '#')
		if (!(ptr->next = ft_tetri_lst(copy, i, x + 1, y)))
			return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	if (copy[i + x + (5 * y) + 5] == '#')
		if (!(ptr->next = ft_tetri_lst(copy, i, x, y + 1)))
			return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	if (copy[i + x + (5 * y) - 1] == '#')
		if (!(ptr->next = ft_tetri_lst(copy, i, x - 1, y)))
			return (NULL);
	return (tetris);
}

t_tetri			**ft_lst_tab(char *fcontent, int nb_tetris)
{
	t_tetri	**tetris;
	char	*copy;
	int		i;
	int		n;

	if (!(tetris = (t_tetri **)malloc(sizeof(t_tetri *) * nb_tetris)))
		return (NULL);
	if (!(copy = ft_strdup(fcontent)))
		return (NULL);
	i = 0;
	n = 0;
	while (n < nb_tetris)
	{
		while (copy[i] != '#')
			i++;
		if (!(tetris[n] = ft_tetri_lst(copy, i, 0, 0)))
			return (NULL);
		while (copy[i] && !(copy[i] == '\n' && copy[i + 1] == '\n'))
			i++;
		n++;
	}
	free(copy);
	return (tetris);
}
