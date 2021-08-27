/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:43:45 by demikael          #+#    #+#             */
/*   Updated: 2021/08/26 23:52:51 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf
#include <stdlib.h> // free
#include <fcntl.h> //open
#include <unistd.h> // read

char	*get_next_line(int fd)
{



	char	*buffer;
	size_t		BUFFER_SIZE;
	static char	*box;
	char		*substring;
	size_t		i;




	BUFFER_SIZE = 13;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);

	i = 0;
	box = ft_strdup("");
	while(buffer[i] && buffer[i] != '\n')
	{
		i++;
		if (i >= BUFFER_SIZE - 1  && (buffer[i] || buffer[i] != '\n'))
		{
			box = ft_strjoin(box, buffer);

			read(fd, buffer, BUFFER_SIZE);
			i = 0;
		}
	}
	substring = ft_substr(buffer, 0, i);
	box = ft_strjoin(box, substring);
	return (box);
}



int	main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	printf("\n== fim ==\n");
	free(str);
	return (0);
}
