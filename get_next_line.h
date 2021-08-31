/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:00:54 by demikael          #+#    #+#             */
/*   Updated: 2021/08/31 15:55:56 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
#endif
