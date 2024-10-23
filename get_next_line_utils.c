/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:03 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/10/23 15:45:59 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h> /*For the open() used here for testing*/

char *ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*s++)
		;
	return (s - str - 1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*jn;
	
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

#include <stdio.h>

// int main()
// {
// 	char s1[] = "I am ";
// 	char s2[] = "a pig!";
// 	char *new = join(s1, s2);
// 	if (new)
// 	{
// 		printf("%s\n", new);
// 		free (new);
// 	}
// 	return(0);
// }