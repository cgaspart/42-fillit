/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:07:13 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/20 07:03:15 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	int				i1;
	int				j1;
	int				i2;
	int				j2;
	int				i3;
	int				j3;
	int				i4;
	int				j4;
	struct s_tetri	*next;
}					t_tetri;

int					ft_verif(char *fcontent);
char				*ft_mapgen(int nbrblock);
int					ft_htag_count(char *fcontent);
char				*ft_reader(char *fname);
int					ft_blocks_analyzer(char *fcontent);
t_tetri				*ft_lst_tab(char *fcontent);
char				*ft_solve(int size, int blocks, t_tetri *tetris);

#endif
