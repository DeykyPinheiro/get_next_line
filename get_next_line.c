/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:43:45 by demikael          #+#    #+#             */
/*   Updated: 2021/08/30 20:29:30 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf
#include <stdlib.h> // free
#include <fcntl.h> //open
#include <unistd.h> // read


char	*get_next_line(int fd)
{

	char		*buffer;
	size_t		BUFFER_SIZE;
	static char	*box;
	static size_t		i;
	int			n;
	static char	**aux;
	char		*line;

	BUFFER_SIZE = 300;

	// if (box)
	// {
	// 	*aux = ft_strdup(&box[i + 1]);


	// }


	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);

	i = 0;
	n = 0;
	box = ft_strdup("");
	line = ft_strdup("");
	while(buffer[i] && buffer[i] != '\n')
	{
		i++;
		if (i >= BUFFER_SIZE - 1  && (buffer[i] || buffer[i] != '\n'))
		{
			box = ft_strjoin(box, buffer);
			read(fd, buffer, BUFFER_SIZE);
			i = 0;
			n ++;
		}
	}
	box = ft_strjoin(box, buffer);
	line = ft_substr(box, 0, i);
	box = ft_strdup(&box[i + 1]);
	return (line);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	printf("\n== fim ==\n");
	free(str);
	return (0);
}
