/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:00:54 by demikael          #+#    #+#             */
/*   Updated: 2021/09/03 18:35:41 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

/**
 * @brief Reads a line from a file descriptor
 *
 * @param fd File descriptor to read.
 * @return Return a string including \\n if is a line. In case of the file
 * dont have \\n return a string without \\n, NULL if the file is empty
 * or error occurred.
 */
char	*get_next_line(int fd);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string
 * ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Returns a pointer to a null-terminated byte string, which is a
 * duplicate of the string pointed to by str. The returned pointer must be
 * passed to free to avoid a memory leak. If an error occurs, a null pointer
 * is returned and errno may be set.
 *
 * @param s Pointer to the null-terminated byte string to duplicate.
 * @return A pointer to the newly allocated string, or a null pointer
 * if an error occurred.
 */
char	*ft_strdup(const char *str);

/**
 * @brief Computes the length of the string s up to, but not including the
 * terminating null character. Example: ft_strlen("1234") => 4
 *
 * @param s This is the string whose length is to be found.
 * @return This function returns the length of string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Searches for the first occurrence of the character c
 * (an unsigned char) in the string pointed to by the argument s. The
 * terminating null	character is considered	part of	the string; therefore
 * if c is \\0, the functions locate the terminating \\0.
 *
 * @param s This is the C string to be scanned.
 * @param c This is the character to be located. It is passed as int,
 * but it is internally converted back to char.
 * @return This returns a pointer to the first occurrence of the character c
 * in the string s, or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c);
#endif
