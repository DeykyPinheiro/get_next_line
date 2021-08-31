/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:43:45 by demikael          #+#    #+#             */
/*   Updated: 2021/08/31 12:36:05 by demikael         ###   ########.fr       */
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
	size_t		size;
	size_t		i;
	int			n; // LEMBRAR DE EXLUIR O C
	static char	**aux;
	char		*line;

	BUFFER_SIZE = 15;

	if (!box)
		box = ft_strdup("");

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	box = ft_strjoin(box, buffer);

	i = 0;
	n = 0;
	size = 0;
	while(box[i + size] != '\0' && box[i + size] != '\n') // deu ruim pq não to verificando buffer
	{
		// se ele for maior que o bz, significa que eu verifiquei tudo e não encontrei uma linha
		i++;
		if (i >= BUFFER_SIZE)
		{
			//dai eu leio novamente e pego outra parte do buffer
			//e faco um join com box e buffer
			read(fd, buffer, BUFFER_SIZE);
			box = ft_strjoin(box, buffer);
			size ++;
			i = 0;
			n ++;
		}
	}
	line = ft_substr(box, 0, size + i + 1); // extraio uma linha e devolvo
	box = ft_strdup(&box[size + i + 1]);
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
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	printf("\n== fim ==\n");
	free(str);
	return (0);
}
