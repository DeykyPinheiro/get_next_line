/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:43:45 by demikael          #+#    #+#             */
/*   Updated: 2021/09/02 16:38:05 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf
#include <stdlib.h> // free
#include <fcntl.h> //open
#include <unistd.h> // read

static void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}

static char	*extract_line(char **str)
{
	char	*line;
	size_t	i;
	char	*aux;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	aux = *str;
	line = ft_substr(aux, 0, i + 1);
	*str = ft_strdup(aux + i + 1);
	free_ptr(&aux);
	return (line);
}

char	*hold_text(int fd, char *buffer, char *box, int *size)
{
	char	*aux;

	while (!ft_strchr(box, '\n') && *size)
	{
		*size = read(fd, buffer, BUFFER_SIZE);
		if (*size <= 0)
			break ;
		buffer[*size] = '\0';
		aux = box;
		box = ft_strjoin(aux, buffer);
		free_ptr(&aux);
	}
	free_ptr(&buffer);
	return (box);
}

static char	*extract_last_line(char **box)
{
	char	*aux;

	if (!ft_strchr(*box, '\n') && **box)
	{
		aux = ft_strdup(*box);
		free_ptr(box);
		return (aux);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*box[OPEN_MAX];
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!box[fd])
		box[fd] = ft_strdup("");
	size = 1;
	box[fd] = hold_text(fd, buffer, box[fd], &size);
	if (size <= 0 && *box[fd] == '\0')
	{
		free_ptr(&box[fd]);
		return (NULL);
	}
	if (ft_strchr(box[fd], '\n'))
		return (extract_line(&box[fd]));
	return (extract_last_line(&box[fd]));
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
