/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:43:45 by demikael          #+#    #+#             */
/*   Updated: 2021/08/31 15:15:10 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf
#include <stdlib.h> // free
#include <fcntl.h> //open
#include <unistd.h> // read



static void free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}

static char *extract_line(char **str)
{
	char	*line;
	size_t	i;
	char	*aux;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
	{
		i++;
	}
	aux = *str;
	line = ft_substr(aux, 0, i + 1);
	*str = ft_strdup(aux + i + 1);
	free_ptr(&aux);
	return (line);
}

char	*get_next_line(int fd)
{

	char		*buffer;
	static char	*box;
	char		*aux;
	size_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!box)
		box = ft_strdup("");

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);

	size = 1;
	if (!ft_strchr(box, '\n'))
	{

		while (!ft_strchr(box, '\n') && size)
			{
				size = read(fd, buffer, BUFFER_SIZE);
				buffer[size] = '\0';
				aux = box;
				box = ft_strjoin(aux, buffer);
				free_ptr(&aux);
			}
	}
	free_ptr(&buffer);
	if (!ft_strchr(box, '\n') && box[0] == '\0')
	{
		free_ptr (&box);
		return (NULL);
	}
	if (ft_strchr(box, '\n'))
		return (extract_line(&box));
	return (NULL);
}

// int main(void)
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	while(1)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 			break ;
// 		printf("%s", str);
// 		free(str);
// 	}
// 	return (0);
// }


