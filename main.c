/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:10:01 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/07 16:29:55 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_first_step(char *fcontent)
{
	if (!(ft_verif(fcontent)))
		return (0);
	return (ft_blocks_analyzer(fcontent));
}

static char	*ft_second_step(char *fcontent, int blocks)
{
	int		i;
	t_tetri	*tetris;

	i = 1;
	if (!(tetris = ft_lst_tab(fcontent)))
		return (NULL);
	return (ft_solve(ft_sqrt(blocks * 4), blocks, tetris));
}

int			main(int argc, char **argv)
{
	int		blocks;
	char	*fcontent;
	char	*map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit tetriminos_file\n");
		exit(0);
	}
	fcontent = ft_reader(argv[1]);
	if (!fcontent || !fcontent[0] || !(blocks = ft_first_step(fcontent)))
	{
		ft_putstr("error\n");
		exit(0);
	}
	if (!(map = ft_second_step(fcontent, blocks)))
		exit(0);
	ft_putstr(map);
	return (0);
}
