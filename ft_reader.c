/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:08:53 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/27 11:52:19 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_reader(char *fname)
{
	int		fd;
	int		ret;
	char	buff[9000];

	fd = open(fname, O_RDONLY);
	if (fd != -1)
	{
		ret = read(fd, buff, 9000);
		buff[ret] = '\0';
		close(fd);
	}
	if (fd == -1)
		return (0);
	return (ft_strdup(buff));
}
