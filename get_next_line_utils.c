/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:59:00 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/11/02 10:50:28 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*s++)
		;
	return (s - str - 1);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	char	*start;

	if (!s)
		return (NULL);/**/
	new = (char *)malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	start = new;
	while (*s)
		*new++ = *s++;
	*new = '\0';
	return (start);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*jn;

	if (!s1 || !s2)
		return (NULL);
	jn = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!jn)
		return (0);
	str = jn;
	while (*s1)
		*jn++ = *s1++;
	while (*s2)
		*jn++ = *s2++;
	*jn = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

void	*f_calloc(size_t n, size_t size)
{
	void	*point;

	if (!n || !size)
		return (NULL);
	if (n * size / size != n)
		return (NULL);
	point = (void *)malloc(n * size);
	if (!point)
		return (NULL);
	while (n--)
		((unsigned char *)point)[n] = (unsigned char)0;
	return (point);
}

// char	*sncopy(char *dest, const char *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && src[i] != '\0')
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	while (i < n)
// 	{
// 		dest[i] = '\0';
// 		i++;
// 	}
// 	return (dest);
// }
