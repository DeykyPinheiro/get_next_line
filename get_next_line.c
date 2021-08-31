/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:43:45 by demikael          #+#    #+#             */
/*   Updated: 2021/08/31 17:19:50 by demikael         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*box;
	char		*aux;
	ssize_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!box)
		box = ft_strdup("");
	size = 1;
	while (!ft_strchr(box, '\n') && size)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			if (size <= 0)
				break;
			buffer[size] = '\0';
			aux = box;
			box = ft_strjoin(aux, buffer);
			free_ptr(&aux);
		}
	free_ptr(&buffer);
	if (size <= 0 && *box == '\0')
		{
			free_ptr(&box);
			return NULL;
		}
	if (!ft_strchr(box, '\n') && *box)
		{
			aux = ft_strdup(box);
			free_ptr(&box);
			return (aux);
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
// 		str = get_next_line(1000);
// 		if (!str)
// 			break ;
// 		printf("%s", str);
// 		free(str);
// 	}
// 	return (0);
// }


