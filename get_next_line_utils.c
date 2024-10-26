#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


char	*sncopy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

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

char	*ft_strdup(const char *s)
{
	char	*new;
	char	*start;

	new = (char *)malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	start = new;
	while (*s)
		*new++ = *s++;
	*new = '\0';
	return (start);
}
