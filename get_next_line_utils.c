/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:01:20 by demikael          #+#    #+#             */
/*   Updated: 2021/08/27 01:01:15 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = (unsigned char)c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb * size > 2147483647)
		return (0);
	result = malloc(nmemb * size);
	if (!result)
		return (0);
	ft_memset(result, 0, nmemb * size);
	return (result);
}


char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;

	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (0);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}



size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str1 = (char *)ft_calloc(size, sizeof(char));
	if (!str1)
		return (0);
	ft_strlcpy(str1, s1, (ft_strlen(s1) + 1));
	ft_strlcat(str1, s2, size);
	return (str1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_dst;
	size_t	i_src;
	size_t	i;

	if (!dst && !src)
		return (0);
	i_dst = 0;
	i_src = ft_strlen(src);
	i = 0;
	while (dst[i_dst] && i_dst < size)
		i_dst++;
	if (i_dst >= size)
		return (i_dst + i_src);
	while (src[i] && (i_dst + i) < size - 1)
	{
		dst[i_dst + i] = src[i];
		i++;
	}
	dst[i_dst + i] = 0;
	return (i_dst + i_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	else if (start + len > s_len)
		len = s_len - start;
	substring = ft_calloc(sizeof(char), (len + 1));
	if (!substring)
		return (0);
	ft_strlcpy(substring, &s[start], len + 1);
	return (substring);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if ((!dest && !src) || !n)
		return (dest);
	while (n--)
	{
		*str1++ = *str2++;
	}
	return (dest);
}

void	*ft_memmove(void *dst,	const void *src, size_t	len)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str2 = (unsigned char *)src;
	str1 = (unsigned char *)dst;
	if (dst > src)
	{
		while (len--)
		{
			str1[len] = str2[len];
		}
		return (dst);
	}
	else
	{
		return (ft_memcpy(dst, src, len));
	}
}
