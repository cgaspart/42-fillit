/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:08:53 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/06 16:22:11 by pfournel         ###   ########.fr       */
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
	else
		return (NULL);
	return (ft_strdup(buff));
}
