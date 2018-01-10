/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocks_analyzer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:29:01 by pfournel          #+#    #+#             */
/*   Updated: 2017/12/20 07:24:22 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_block_analyze(char *test, int i, int *pieces, int maplen)
{
	test[i] = '*';
	(*pieces)++;
	if (i + 1 < maplen && test[i + 1] == '#')
		ft_block_analyze(test, i + 1, pieces, maplen);
	if (i - 1 < maplen && test[i - 1] == '#')
		ft_block_analyze(test, i - 1, pieces, maplen);
	if (i + 5 < maplen && !(test[i + 1] == '\n' && test[i + 2] == '\n') &&
			!(test[i + 2] == '\n' && test[i + 3] == '\n') &&
			!(test[i + 3] == '\n' && test[i + 4] == '\n') &&
			test[i + 5] == '#')
		ft_block_analyze(test, i + 5, pieces, maplen);
	return (*pieces);
}

int			ft_blocks_analyzer(char *fcontent)
{
	char	*test;
	int		i;
	int		pieces;
	int		blocks;

	if (!(test = ft_strdup(fcontent)))
		return (0);
	i = 0;
	blocks = 1;
	while (test[i])
	{
		pieces = 0;
		if (test[i] == '#')
			if ((ft_block_analyze(test, i, &pieces, (int)ft_strlen(test))) != 4)
			{
				free(test);
				return (0);
			}
		if (test[i] == '\n' && test[i + 1] == '\n')
			blocks++;
		i++;
	}
	free(test);
	return (blocks);
}
