/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:00:54 by demikael          #+#    #+#             */
/*   Updated: 2021/09/02 19:57:06 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

char	*get_next_line(int	fd);
char	*ft_substr(char const	*s, unsigned int	start, size_t	len);
char	*ft_strdup(const char	*s);
size_t	ft_strlen(const char	*str);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_strchr(const char	*str, int	c);
#endif
